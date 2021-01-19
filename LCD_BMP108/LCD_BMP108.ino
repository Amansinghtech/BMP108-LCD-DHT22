#include <LiquidCrystal.h>
#include <Wire.h>
#include <Adafruit_BMP085.h>
#include "DHT.h"
#define DHTPIN 11
#define seaLevelPressure_hPa 1013.25
Adafruit_BMP085 bmp;
#define DHTTYPE DHT22 

// initialize the library by associating any needed LCD interface pin
// with the arduino pin number it is connected to
const int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  Serial.begin(9600);
  dht.begin();
  // set up the LCD's number of columns and rows:
  lcd.begin(16, 2);
  // Print a message to the LCD.
  lcd.print("hello, world!");//comment this out!
  if (!bmp.begin()) {
    lcd.print("Sensor Error");
    while (1) {}
  }
}

void temp(){
  Serial.print("Temperature: ");
  Serial.print(bmp.readTemperature());
  Serial.println(" *C");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Temperature: ");
  lcd.setCursor(0,1);
  lcd.print(bmp.readTemperature());
  lcd.print(" *C");
  delay(300);
  }

void pressure(){
  Serial.print("Pressure: ");
  Serial.print(bmp.readPressure());
  Serial.println(" Pa");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Pressure: ");
  lcd.setCursor(0,1);
  lcd.print(bmp.readPressure());
  lcd.print(" Pa");
  delay(300);
  }

void altitude(){
  Serial.print("Altitude: ");
  Serial.print(bmp.readAltitude(seaLevelPressure_hPa * 100));
  Serial.println(" Meters");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Altitude: ");
  lcd.setCursor(0,1);
  lcd.print(bmp.readAltitude(seaLevelPressure_hPa * 100));
  lcd.print(" Meters");
  delay(300);
  }

void seaLevel(){
  Serial.print("PressureSea LvL:");
  Serial.print(bmp.readSealevelPressure());
  Serial.println(" Pa");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("PressureSea LvL:");
  lcd.setCursor(0,1);
  lcd.print(bmp.readSealevelPressure());
  lcd.print(" Pa");
  delay(300);
  }

void humidity(){
  Serial.print("PressureSea LvL:");
  Serial.print(bmp.readSealevelPressure());
  Serial.println(" Pa");
  lcd.clear();
  lcd.setCursor(0,0);
  lcd.print("Humidity:");
  lcd.setCursor(0,1);
  float h = dht.readHumidity();
    if (isnan(h)){
        lcd.print("404 Not Found");
        return 0;
      }
  lcd.print(h);
  lcd.print(" %");
  delay(300);
  }

void loop() {
  
  temp();
  delay(3000);
  pressure();
  delay(3000);
  humidity();
  delay(3000);
  //altitude();
  //delay(3000);
  //seaLevel();
  //delay(3000);
}
