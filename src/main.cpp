#include <Arduino.h>
#include <Wire.h>

#include <WiFi.h>
const char *ssid = "Kloudtech Weather Data";
const char *password = "kloudtech";

#include <ESPAsyncWebServer.h>

#include <PageIndex.h>
AsyncWebServer server(80);
AsyncEventSource events("/events");

// TIMERS
unsigned long lastTime1 = 0;
unsigned long lastTime2 = 0;
unsigned long Timer1 = 1000; // send readings timer
unsigned long Timer2 = 3000; // send readings timer

int rainArray[201];
int windArray[201];
float gustArray[201];

// BME
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
#define BME_SDA 21
#define BME_SCL 22
Adafruit_BME280 bme;
float t1 = 0;
float h1 = 0;
float p1 = 0;

// BMP
#include <Adafruit_BMP085.h>
Adafruit_BMP085 bmp;
float t2;
float p2;

// DHT22 Library
#include <DHT.h>
#define DHTPIN 04
#define DHTTYPE DHT22
DHT dht(DHTPIN, DHTTYPE);
float h2;

// AS5600 Library
int magnetStatus = 0; // value of the status register (MD, ML, MH)

int lowbyte;    // raw angle 7:0
word highbyte;  // raw angle 7:0 and 11:8
int rawAngle;   // final raw angle
float degAngle; // raw angle in degrees (360/4096 * [value between 0-4095])

int quadrantNumber, previousquadrantNumber; // quadrant IDs
float numberofTurns = 0;                    // number of turns
float correctedAngle = 0;                   // tared angle - based on the startup value
float startAngle = 0;                       // starting angle
float totalAngle = 0;                       // total absolute angular displacement
float previoustotalAngle = 0;               // for the display printing

// BH1750 Library
#include <BH1750.h>
BH1750 lightMeter;
float lux = 0;
float irradiance = 0;

// UV Library
#define UVPIN 32
float sensorVoltage;
float sensorValue;
int UV_index;

// Slave Library
#define SLAVE 0x03
#define countof(a) (sizeof(a) / sizeof(a[0]))

// Precipitation
float tipValue = 0.1099, rain;
uint16_t receivedRainCount;
int currentRainCount;
RTC_DATA_ATTR int prevRainCount;

// Wind Speed
float windspeed;
int REV, radius = 51; // Changed radius from 100 to 51
uint16_t receivedWindCount;
int currentWindCount;
RTC_DATA_ATTR int prevWindCount;
float gust;

// SD Card
#include "FS.h"
#include "SD.h"
#include "SPI.h"
#define SCK 14
#define MISO 2
#define MOSI 15
#define CS 13
SPIClass spi = SPIClass(VSPI);
char data[100];

// Time
#include "RTClib.h"
RTC_DS3231 rtc;

void appendFile(fs::FS &fs, String path, String message)
{
  // Serial.printf("Appending to file: %s\n", path);
  File file = fs.open(path, FILE_APPEND);
  // if (!file) {
  //   Serial.println("Failed to open file for appending");
  //   return;
  // }
  // if (file.println(message)) {
  //   Serial.println("Message appended");
  // }
  // else {
  //   Serial.println("Append failed");
  // }
  file.close();
  // Serial.println("File Closed");
}

void createHeader(fs::FS &fs, String path, String message)
{
  // Serial.printf("Checking if %s exists...", path);

  File file = fs.open(path);
  if (!file)
  {
    // Serial.print("\nFile does not exist creating header files now...");
    File file = fs.open(path, FILE_APPEND);
    // if (file.println(message))
    // {
    //   Serial.println(" >OK");
    // }
    // else
    // {
    //   Serial.println(" >Failed");
    // }
    return;
  }
  // Serial.println(" >OK");
  file.close();
  // Serial.println("File Closed");
}

String getFileName()
{
  DateTime now = rtc.now();
  char fileNameString[20]; // adjust the size as needed
  sprintf(fileNameString, "/%04d%02d%02d.csv", now.year(), now.month(), now.day());
  return String(fileNameString);
}

String getTime()
{
  DateTime now = rtc.now();
  String timeString = String(now.year(), DEC) + "-" +
                      String(now.month(), DEC) + "-" +
                      String(now.day(), DEC) + " " +
                      String(now.hour(), DEC) + ":" +
                      String(now.minute(), DEC) + ":" +
                      String(now.second(), DEC);
  return timeString;
}

// Saving to SD Card
void logDataToSDCard()
{
  if (!SD.begin(CS, spi))
  {
    Serial.println(" >Failed. Skipping SD Storage");
  }
  else
  {
    Serial.println("SD Card Initiation Complete");
    String filename = getFileName();
    String datetime = getTime();
    sprintf(data, ",%.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f, %.2f", t1, h1, p1, t2, h2, p2, correctedAngle, lux, UV_index, rain, windspeed);
    String log = datetime + data;

    createHeader(SD, filename, "Date, Temperature 1, Humidity 1, Pressure 1, Temperature 2, Humidity 2, Pressure 2, Wind Direction, Light Intensity, UV Intensity, Precipitation, Wind Speed");
    appendFile(SD, filename, log);

    Serial.print("Data Logged: ");
    Serial.println(log);
    Serial.println();
  }
}

// Sensor readings
void initBMEBMPDHT()
{
  t1 = bme.readTemperature();
  h1 = bme.readHumidity();
  p1 = bme.readPressure() / 100;
  t2 = bmp.readTemperature();
  p2 = bmp.readPressure() / 100;
  h2 = dht.readHumidity();
}

void handleWindDirection()
{
  Wire.beginTransmission(0x36); // connect to the sensor
  Wire.write(0x0D);             // figure 21 - register map: Raw angle (7:0)
  Wire.endTransmission();       // end transmission
  Wire.requestFrom(0x36, 1);    // request from the sensor

  while (Wire.available() == 0)
    ;                    // wait until it becomes available
  lowbyte = Wire.read(); // Reading the data after the request

  // 11:8 - 4 bits
  Wire.beginTransmission(0x36);
  Wire.write(0x0C); // figure 21 - register map: Raw angle (11:8)
  Wire.endTransmission();
  Wire.requestFrom(0x36, 1);

  while (Wire.available() == 0)
    ;
  highbyte = Wire.read();

  // 4 bits have to be shifted to its proper place as we want to build a 12-bit number
  highbyte = highbyte << 8;      // shifting to left
  rawAngle = highbyte | lowbyte; // int is 16 bits (as well as the word)
  degAngle = rawAngle * 0.087890625;

  // recalculate angle
  correctedAngle = degAngle - 11; // this tares the position

  if (correctedAngle < 0) // if the calculated angle is negative, we need to "normalize" it
  {
    correctedAngle = correctedAngle + 360; // correction for negative numbers (i.e. -15 becomes +345)
  }

  correctedAngle = correctedAngle;

  if (correctedAngle > 360) // if the calculated angle is negative, we need to "normalize" it
  {
    correctedAngle = correctedAngle - 360; // correction for negative numbers (i.e. -15 becomes +345)
  }

  correctedAngle = 360 - correctedAngle;
}

void handleLight()
{
  lux = lightMeter.readLightLevel();
}

void handlePrecipitation()
{
  Serial.println("==========Connecting to Rain Gauge==========");

  Wire.begin();
  Wire.requestFrom(SLAVE, 4);
  while (2 < Wire.available())
  {
    byte msb = Wire.read();
    byte lsb = Wire.read();
    receivedRainCount = (msb << 8) | lsb;
  }

  for (int i = 200; i > 0; i--)
  {
    rainArray[i] = rainArray[i - 1];
  }
  rainArray[0] = receivedRainCount;

  Serial.printf("Current Rain Count: %.2i \n", currentRainCount);
  Serial.printf("Recieved Rain Count: %.2i \n", rainArray[0]);
  Serial.printf("Previous Rain Count: %.2i \n", rainArray[6]);

  if ((rainArray[0] - rainArray[200]) > -1)
  {
    rain = (rainArray[0] - rainArray[200]) * tipValue;
  }
  else
  {
    rain = (65535 + rainArray[0] - rainArray[200]) * tipValue;
  }

  Serial.printf("Rain Measurement: %.2f \n", rain);
}

void handleWindSpeed()
{
  while (Wire.available())
  {
    byte msb = Wire.read();
    byte lsb = Wire.read();
    receivedWindCount = (msb << 8) | lsb;
  }

  for (int i = 200; i > 0; i--)
  {
    windArray[i] = windArray[i - 1];
  }
  windArray[0] = receivedWindCount;

  if ((windArray[0] - windArray[200]) > -1)
  {
    REV = (windArray[0] - windArray[200]);
  }
  else
  {
    REV = (65355 + windArray[0] - windArray[200]);
  }

  float period = 3 * 200;
  Serial.printf("Time Elapsed: %i", period);
  Serial.printf("Revolutions: %i", REV);
  windspeed = ((REV * 2 * PI * radius / 1000) / period) * 3.6;

  float gust_period = 3;
  float gust_i = ((REV * 2 * PI * radius / 1000) / gust_period) * 3.6;
  for (int i = 200; i > 0; i--)
  {
    gustArray[i] = gustArray[i - 1];
  }
  gustArray[0] = gust_i;
  int n = sizeof(gustArray) / sizeof(gustArray[0]);

  int maxGust = gustArray[0];

  for (int i = 1; i < n; ++i)
  {
    if (gustArray[i] > maxGust)
    {
      maxGust = gustArray[i]; // Update maxVal if the current element is greater
    }
  }
  gust = maxGust;
}

String processor(const String &var)
{
  initBMEBMPDHT();
  handleWindDirection();
  handleLight();
  handlePrecipitation();
  handleWindSpeed();
  // Serial.println(var);
  if (var == "T1")
  {
    return String(t1);
  }
  else if (var == "H1")
  {
    return String(h1);
  }
  else if (var == "P1")
  {
    return String(p1);
  }
  else if (var == "T2")
  {
    return String(t2);
  }
  else if (var == "H2")
  {
    return String(h2);
  }
  else if (var == "P2")
  {
    return String(p2);
  }
  else if (var == "WINDDIR")
  {
    return String(correctedAngle);
  }
  else if (var == "LIGHT")
  {
    return String(lux);
  }
  else if (var == "UV")
  {
    return String(UV_index);
  }
  else if (var == "RAIN")
  {
    return String(rain);
  }
  else if (var == "WINDSPEED")
  {
    return String(windspeed);
  }
  else if (var == "GUST")
  {
    return String(gust);
  }
}

void setup()
{
  // Initialize Serial Monitor
  Serial.begin(115200);
  delay(500);
  Serial.println("=====Opening Serial Monitor====");

  // Set-up Access Point
  Serial.println("Setting AP...");
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  Serial.print("AP IP address: ");
  Serial.println(IP);

  // Initialize Wire I2C
  Wire.begin(21, 22);

  // Initialize RTC
  if (!rtc.begin())
  {
    Serial.println("Skipping RTC Initialization");
  }
  else
  {
    Serial.println("RTC Initiation Complete");
  }

  // Initialize BME
  if (!bme.begin(0x76))
  {
    Serial.println("Could not find a valid BME280 sensor, check wiring!");
    while (1)
      ;
  }
  else
  {
    Serial.println("BME Initiation Complete");
  }
  delay(10);

  // Initialize BMP
  if (!bmp.begin())
  {
    Serial.println("Could not find a valid BMP180 sensor, check wiring!");
    while (1)
      ;
  }
  else
  {
    Serial.println("BMP Initiation Complete");
  }
  delay(10);

  // Initialize DHT
  dht.begin();
  if (isnan(h2))
  {
    Serial.println("Could not find a valid DHT22 sensor, check wiring!");
  }
  else
  {
    Serial.println("DHT Initiation Complete");
  }
  delay(10);

  // Initialize Light sensor
  if (!lightMeter.begin())
  {
    Serial.println("Could not find a valid BH1750 sensor, check wiring!");
  }
  else
  {
    Serial.println("BH1750 Initiation Complete");
  }

  // Initialize UV
  if (isnan(sensorValue))
  {
    Serial.println("Could not find a valid UV sensor, check wiring!");
  }
  else
  {
    Serial.println("UV Initiation Complete");
  }

  // Initialize Slave
  if (!Wire.begin())
  {
    Serial.println("Could not find a valid Slave Device, check wiring!");
  }
  else
  {
    Serial.println("Slave Initiation Complete");
  }

  // Initialize SD Card
  spi.begin(SCK, MISO, MOSI, CS);

  // Handle Web Server
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
            { request->send_P(200, "text/html", MAIN_page, processor); });

  // Handle Web Server Events
  events.onConnect([](AsyncEventSourceClient *client)
                   {
    if(client->lastId()){
      Serial.printf("Client reconnected! Last message ID that it got is: %u\n", client->lastId());
    }
    // send event with message "hello!", id current millis
    // and set reconnect delay to 1 second
    client->send("hello!", NULL, millis(), 10000); });
  server.addHandler(&events);
  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  if ((millis() - lastTime1) > Timer1)
  {
    initBMEBMPDHT();
    handleWindDirection();
    handleLight();
    // Send Events to the Web Server with the Sensor Readings
    events.send("ping", NULL, millis());
    events.send(String(correctedAngle).c_str(), "correctedAngle", millis());
    events.send(String(lux).c_str(), "lux", millis());
    events.send(String(t1).c_str(), "t1", millis());
    events.send(String(h1).c_str(), "h1", millis());
    events.send(String(p1).c_str(), "p1", millis());
    events.send(String(t2).c_str(), "t2", millis());
    events.send(String(h2).c_str(), "h2", millis());
    events.send(String(p2).c_str(), "p2", millis());
    lastTime1 = millis();
  }

  if ((millis() - lastTime2) > Timer2)
  {
    handlePrecipitation();
    handleWindSpeed();
    // Send Events to the Web Server with the Sensor Readings
    events.send("ping", NULL, millis());
    events.send(String(rain).c_str(), "rain", millis());
    events.send(String(windspeed).c_str(), "windspeed", millis());
    events.send(String(gust).c_str(), "gust", millis());
    lastTime2 = millis();
  }
}