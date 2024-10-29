#include <Arduino.h>
#include <Wire.h>

#include <WiFi.h>
// const char *ssid = "Kloudtech Weather Data";
// const char *password = "kloudtech";
const char *ssid = "KT 2.4";
const char *password = "J@yGsumm!t";

#include <WebServer.h>
#include <PageIndex.h>
// #include <PageIndexCss.h>
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

String windSpeedStr = "";

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

// Wind Speed and Gust var
float windspeed;
int radius = 50, period = 60;
uint16_t receivedWindCount = 0;
float gust;
uint16_t receivedGustCount = 0;

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

void handleRootHtml()
{
  String html = MAIN_page;             // Read HTML contents
  server.send(200, "text/html", html); // Send web page
}

// void handleRootCss()
// {
//   String css = MAIN_page_css;             // Read HTML contents
//   server.send(200, "text/css", css); // Send web page
// }

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

void handleWindSpeed()
{
  // Wind speed
  if (Wire.available() >= 2) {
    byte msb = Wire.read();
    byte lsb = Wire.read();
    receivedWindCount = (msb << 8) | lsb;
  }
  windspeed = (2 * PI * radius * receivedWindCount * 3.6) / (period * 1000);
  windSpeedStr = String(windspeed);
  server.send(200, "text/plain", windSpeedStr);
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
  // if (!bme.begin(0x76))
  // {
  //   Serial.println("Could not find a valid BME280 sensor, check wiring!");
  //   while (1)
  //     ;
  // }
  // else
  // {
  //   Serial.println("BME Initiation Complete");
  // }
  // delay(10);

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
  server.on("/", handleRootHtml);
  // server.on("/output.css", handleRootCss);
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
  server.on("/readWindSpeed", handleWindSpeed);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  server.handleClient(); // Handle client requests
}