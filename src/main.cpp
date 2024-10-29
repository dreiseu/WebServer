#include <Arduino.h>
#include <Wire.h>

#include <WiFi.h>
// const char *ssid = "Kloudtech Weather Data";
// const char *password = "kloudtech";
const char *ssid = "KT 2.4";
const char *password = "J@yGsumm!t";

#include <WebServer.h>
#include <PageIndex.h>
WebServer server(80); // Web server on port 80

// Sleep Factors
#define uS_TO_S_FACTOR 1000000ULL /* Conversion factor for micro seconds to seconds */
#define TIME_TO_SLEEP 60          /* Time ESP32 will go to sleep (in seconds) */

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

// void readFile(fs::FS &fs, String path){
//   Serial.printf("Reading file: %s\n", path);

//   File file = fs.open(path);
//   if(!file){
//     Serial.println("Failed to open file for reading");
//     return;
//   }

//   Serial.print("Read from file: ");
//   while(file.available()){
//     Serial.write(file.read());
//   }
//   file.close();
//   Serial.println("File Closed");
// }

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

void handleRoot()
{
  String s = MAIN_page;             // Read HTML contents
  server.send(200, "text/html", s); // Send web page
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
void handleBMETemperature()
{
  t1 = bme.readTemperature();
  String Temperature1_Value = String(t1);
  server.send(200, "text/plain", Temperature1_Value); // Send Temperature value only to client ajax request
}

void handleBMEHumidity()
{
  h1 = bme.readHumidity();
  String Humidity1_Value = String(h1);
  server.send(200, "text/plain", Humidity1_Value); // Send Temperature value only to client ajax request
}

void handleBMEPressure()
{
  p1 = bme.readPressure() / 100;
  String Pressure1_Value = String(p1);
  server.send(200, "text/plain", Pressure1_Value); // Send Temperature value only to client ajax request
}

void handleBMPTemperature()
{
  t2 = bmp.readTemperature();
  String Temperature2_Value = String(t2);
  server.send(200, "text/plain", Temperature2_Value);
}

void handleBMPPressure()
{
  p2 = bmp.readPressure() / 100;
  String Pressure2_Value = String(p2);
  server.send(200, "text/plain", Pressure2_Value);
}

void handleDHTHumidity()
{
  h2 = dht.readHumidity();
  String Humidity2_Value = String(h2);
  server.send(200, "text/plain", Humidity2_Value);
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
  correctedAngle = degAngle - startAngle; // this tares the position

  if (correctedAngle < 0) // if the calculated angle is negative, we need to "normalize" it
  {
    correctedAngle = correctedAngle + 360; // correction for negative numbers (i.e. -15 becomes +345)
  }

  correctedAngle = correctedAngle + 170;

  if (correctedAngle > 360) // if the calculated angle is negative, we need to "normalize" it
  {
    correctedAngle = correctedAngle - 360; // correction for negative numbers (i.e. -15 becomes +345)
  }

  correctedAngle = 360 - correctedAngle;

  String WindDirection_Value = String(correctedAngle);
  server.send(200, "text/plain", WindDirection_Value);
}

void handleLight()
{
  lux = lightMeter.readLightLevel();
  String Light_Value = String(lux);
  server.send(200, "text/plain", Light_Value);
}

void handleUV()
{
  sensorValue = analogRead(UVPIN);
  sensorVoltage = sensorValue * (3.3 / 4095);
  UV_index = sensorVoltage / 0.1;
  String UV_Value = String(UV_index);
  server.send(200, "text/plain", UV_Value);
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

  Serial.printf("Current Rain Count: %.2i \n", currentRainCount);
  Serial.printf("Recieved Rain Count: %.2i \n", receivedRainCount);
  currentRainCount = receivedRainCount;

  Serial.printf("Previous Rain Count: %.2i \n", prevRainCount);
  if ((currentRainCount - prevRainCount) > -1)
  {
    rain = (currentRainCount - prevRainCount) * tipValue;
  }
  else
  {
    rain = (65535 + currentRainCount - prevRainCount) * tipValue;
  }

  Serial.printf("Rain Measurement: %.2f \n", rain);
  prevRainCount = currentRainCount;

  String Precipitation_Value = String(rain);
  server.send(200, "text/plain", Precipitation_Value);
}

void handleWindSpeed()
{
  while (Wire.available())
  {
    byte msb = Wire.read();
    byte lsb = Wire.read();
    receivedWindCount = (msb << 8) | lsb;
  }
  currentWindCount = receivedWindCount;
  if ((currentWindCount - prevWindCount) > -1)
  {
    REV = (currentWindCount - prevWindCount);
  }
  else
  {
    REV = (65355 + currentWindCount - prevWindCount);
  }

  int previousTime;
  int currentTime = millis();
  Serial.printf("Current Time: %i", currentTime);
  float period = (currentTime - previousTime) / 1000;
  Serial.printf("Time Elapsed: %.4f", period);
  Serial.printf("Revolutions: %i", REV);
  windspeed = ((2 * PI * radius / 1000 * REV) / period) * 3.6;

  previousTime = currentTime;

  prevWindCount = currentWindCount;
  String WindSpeed_Value = String(windspeed);
  server.send(200, "text/plain", WindSpeed_Value);
  logDataToSDCard();
}

void setup()
{
  // Initialize Serial Monitor
  Serial.begin(115200);
  delay(500);
  Serial.println("=====Opening Serial Monitor====");

  // Set-up Access Point
  // Serial.println("Setting AP...");
  // WiFi.softAP(ssid, password);
  // IPAddress IP = WiFi.softAPIP();
  // Serial.print("AP IP address: ");
  // Serial.println(IP);

  Serial.print("Connecting to ");
  Serial.println(ssid);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  // Print local IP address and start web server
  Serial.println("");
  Serial.println("WiFi connected.");
  Serial.println("IP address: ");
  Serial.println(WiFi.localIP());

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
  // if (!bmp.begin())
  // {
  //   Serial.println("Could not find a valid BMP180 sensor, check wiring!");
  //   while (1)
  //     ;
  // }
  // else
  // {
  //   Serial.println("BMP Initiation Complete");
  // }
  // delay(10);

  // // Initialize DHT
  // dht.begin();
  // if (isnan(h2))
  // {
  //   Serial.println("Could not find a valid DHT22 sensor, check wiring!");
  // }
  // else
  // {
  //   Serial.println("DHT Initiation Complete");
  // }
  // delay(10);

  // // Initialize Light sensor
  // if (!lightMeter.begin())
  // {
  //   Serial.println("Could not find a valid BH1750 sensor, check wiring!");
  // }
  // else
  // {
  //   Serial.println("BH1750 Initiation Complete");
  // }

  // // Initialize UV
  // if (isnan(sensorValue))
  // {
  //   Serial.println("Could not find a valid UV sensor, check wiring!");
  // }
  // else
  // {
  //   Serial.println("UV Initiation Complete");
  // }

  // // Initialize Slave
  // if (!Wire.begin())
  // {
  //   Serial.println("Could not find a valid Slave Device, check wiring!");
  // }
  // else
  // {
  //   Serial.println("Slave Initiation Complete");
  // }

  // // Initialize SD Card
  // spi.begin(SCK, MISO, MOSI, CS);

  // Setup Web server routes
  server.on("/", handleRoot);
  server.on("/readBMETemperature", handleBMETemperature);
  server.on("/readBMEHumidity", handleBMEHumidity);
  server.on("/readBMEPressure", handleBMEPressure);
  // server.on("/readBMPTemperature", handleBMPTemperature);
  // server.on("/readBMPPressure", handleBMPPressure);
  // server.on("/readDHTHumidity", handleDHTHumidity);
  // server.on("/readWindDirection", handleWindDirection);
  // server.on("/readLight", handleLight);
  // server.on("/readUV", handleUV);
  // server.on("/readPrecipitation", handlePrecipitation);
  // server.on("/readWindSpeed", handleWindSpeed);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  server.handleClient(); // Handle client requests
}