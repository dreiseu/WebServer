#include <Arduino.h>
#include <Wire.h>

// Serial Monitors
#define SerialMon Serial

#include <WiFi.h>
const char *ssid = "Kloudtech Weather Data";
const char *password = "kloudtech";

#include <WebServer.h>
#include <PageIndex.h>
WebServer server(80); // Web server on port 80

// String Parameters
String t1Str = "";
String h1Str = "";
String p1Str = "";
String t2Str = "";
String h2Str = "";
String p2Str = "";
String t3Str = "";
String h3Str = "";
String p3Str = "";
String lightStr = "";
String uvIntensityStr = "";
String windDirStr = "";
String windSpeedStr = "";
String rainStr = "";
String gustStr = "";
String batteryStr = "";
String communication = "";

// BME
#include <Adafruit_Sensor.h>
#include <Adafruit_BME280.h>
Adafruit_BME280 bme1;
Adafruit_BME280 bme2;
Adafruit_BME280 bme3;
float t1, h1, p1, t2, h2, p2, t3, h3, p3;

// AS5600 Variables
int magnetStatus, lowbyte, rawAngle, correctedAngle;
word highbyte;
float degAngle, startAngle;
RTC_DATA_ATTR float rtcStartAngle;
RTC_DATA_ATTR int rtcCorrectAngle;

// UV Variables
#define uvPin 32
float sensorVoltage, sensorValue;
int uvIntensity;

// BH1750 Library and Variables
#include <BH1750.h>
BH1750 lightMeter;
float lux, irradiance;

// Slave Address
#define SLAVE 0x03

// Rain Gauge
float tipValue = 0.1099, rain;
uint16_t receivedRainCount = 0;

// Wind Speed and Gust var
float windspeed;
int radius = 50, period = 60;
uint16_t receivedWindCount = 0;
float gust;
uint16_t receivedGustCount = 0;

void handleRoot()
{
  String s = MAIN_page;             // Read HTML contents
  server.send(200, "text/html", s); // Send web page
}

// Sensor readings
void select_bus(uint8_t bus) {
  Wire.beginTransmission(0x70);
  Wire.write(1 << bus);
  Wire.endTransmission();
}

void getBME(Adafruit_BME280 bme, int bus, float *temp, float *hum, float *pres) {
  select_bus(bus);
  *temp = bme.readTemperature();
  *hum = bme.readHumidity();
  *pres = bme.readPressure() / 100.0F;
}

void handleBME1temp()
{
  getBME(bme1, 2, &t1, &h1, &p1);
  t1Str = String(t1);
  server.send(200, "text/plain", t1Str); 
}

void handleBME1humid()
{
  getBME(bme1, 2, &t1, &h1, &p1);
  h1Str = String(h1);
  server.send(200, "text/plain", h1Str);
}

void handleBME1pres()
{
  getBME(bme1, 2, &t1, &h1, &p1);
  p1Str = String(p1);
  server.send(200, "text/plain", p1Str);
}

void handleBME2temp()
{
  getBME(bme2, 3, &t2, &h2, &p2);
  t2Str = String(t2);
  server.send(200, "text/plain", t2Str);
}

void handleBME2humid()
{
  getBME(bme2, 3, &t2, &h2, &p2);
  h2Str = String(h2);
  server.send(200, "text/plain", h2Str);
}

void handleBME2pres()
{
  getBME(bme2, 3, &t2, &h2, &p2);
  p2Str = String(p2);
  server.send(200, "text/plain", p2Str);
}

void handleBME3temp()
{
  getBME(bme3, 4, &t3, &h3, &p3);
  t3Str = String(t3);
  server.send(200, "text/plain", t3Str);
}

void handleBME3humid()
{
  getBME(bme3, 4, &t3, &h3, &p3);
  h3Str = String(h3);
  server.send(200, "text/plain", h3Str);
}

void handleBME3pres()
{
  getBME(bme3, 4, &t3, &h3, &p3);
  p3Str = String(p3);
  server.send(200, "text/plain", p3Str);
}

void ReadRawAngle() {
  Wire.beginTransmission(0x36);
  Wire.write(0x0D);
  Wire.endTransmission();
  Wire.requestFrom(0x36, 1);
  lowbyte = Wire.read();

  Wire.beginTransmission(0x36);
  Wire.write(0x0C);
  Wire.endTransmission();
  Wire.requestFrom(0x36, 1);
  highbyte = Wire.read();

  highbyte = highbyte << 8;
  rawAngle = highbyte | lowbyte;
  degAngle = rawAngle * 0.087890625;
}

void correctAngle() {
  correctedAngle = 360 - degAngle + startAngle;
  if (correctedAngle > 360) { correctedAngle -= 360; }
  rtcCorrectAngle = correctedAngle;
  if (correctedAngle == 360) { correctedAngle = 0; }
}

void handleWindDirection()
{
  ReadRawAngle();
  correctAngle();
  windDirStr = String(correctedAngle);
  server.send(200, "text/plain", windDirStr);
}

void handleLight()
{
  lux = lightMeter.readLightLevel();
  lightStr = String(lux);
  server.send(200, "text/plain", lightStr);
}

void handleUV()
{
  sensorValue = analogRead(uvPin);
  sensorVoltage = sensorValue * (3.3 / 4095);
  uvIntensity = sensorVoltage * 1000;
  uvIntensityStr = String(uvIntensity);
  server.send(200, "text/plain", uvIntensityStr);
}

void handlePrecipitation()
{
  // Rain
  if (Wire.available() >= 4) {
    byte msb = Wire.read();
    byte lsb = Wire.read();
    receivedRainCount = (msb << 8) | lsb;
  }
  rain = receivedRainCount * tipValue;
  rainStr = String(rain);
  server.send(200, "text/plain", rainStr);
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

void handleGust()
{
  // Gust
  if (Wire.available() >= 2) {
    byte msb = Wire.read();
    byte lsb = Wire.read();
    receivedGustCount = (msb << 8) | lsb;
  }
  gust = (2 * PI * radius * receivedGustCount * 3.6) / (3 * 1000);
  gustStr = String(gust);
  server.send(200, "text/plain", gustStr);
}

void setup()
{
  // Initialize Serial Monitor
  Wire.begin(21, 22);
  SerialMon.begin(115200);
  delay(500);
  SerialMon.println("=====Opening Serial Monitor====");

  // Set-up Access Point
  SerialMon.println("Setting AP...");
  WiFi.softAP(ssid, password);
  IPAddress IP = WiFi.softAPIP();
  SerialMon.print("AP IP address: ");
  SerialMon.println(IP);

  // Initialize BME 1
  if (!bme1.begin(0x76))
  {
    SerialMon.println("BME1: Failed");
  }
  else
  {
    SerialMon.println("BME1: OK");
  }
  delay(10);

  // Initialize BME 2
  if (!bme2.begin(0x76))
  {
    SerialMon.println("BME2: Failed");
  }
  else
  {
    SerialMon.println("BME2: OK");
  }
  delay(10);

  // Initialize BME 3
  if (!bme3.begin(0x76))
  {
    SerialMon.println("BME3: Failed");
  }
  else
  {
    SerialMon.println("BME3: OK");
  }
  delay(10);

  // Initialize Light sensor
  if (!lightMeter.begin())
  {
    Serial.println("Light: Failed");
  }
  else
  {
    Serial.println("Light: OK");
  }

  // Initialize Direction
  startAngle - rtcStartAngle;
  ReadRawAngle();
  if (rtcStartAngle == 0) { rtcStartAngle = degAngle; }
  startAngle = rtcStartAngle;
  correctedAngle = rtcCorrectAngle;
  Wire.beginTransmission(0x36);
  if (!Wire.endTransmission() == 0) { SerialMon.println("Direction: Failed"); }
  else { SerialMon.println("Direction: OK"); }

  // Initialize Slave
  Wire.beginTransmission(SLAVE);
  if (!Wire.endTransmission() == 0) { SerialMon.println("Slave: Failed"); }
  else { SerialMon.println("Slave: OK"); }
  Wire.requestFrom(SLAVE, 6);

  // Setup Web server routes
  server.on("/", handleRoot);
  server.on("/readBME1temp", handleBME1temp);
  server.on("/readBME2temp", handleBME2temp);
  server.on("/readBME3temp", handleBME3temp);
  server.on("/readBME1humid", handleBME1humid);
  server.on("/readBME2humid", handleBME2humid);
  server.on("/readBME3humid", handleBME3humid);
  server.on("/readBME1pres", handleBME1pres);
  server.on("/readBME2pres", handleBME2pres);
  server.on("/readBME3pres", handleBME3pres);
  server.on("/readWindDirection", handleWindDirection);
  server.on("/readLight", handleLight);
  server.on("/readUV", handleUV);
  server.on("/readPrecipitation", handlePrecipitation);
  server.on("/readWindSpeed", handleWindSpeed);
  server.on("/readGust", handleGust);

  // Start server
  server.begin();
  Serial.println("HTTP server started");
}

void loop()
{
  server.handleClient(); // Handle client requests
}