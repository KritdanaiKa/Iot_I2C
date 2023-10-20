#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>

LiquidCrystal_I2C lcd(0x27 , 16,2);

float temperature;
float humidity;
DHT dht14(D4,DHT11);

void setup() {
  lcd.begin();
  dht14.begin();
  temperature = 0;
  humidity = 0;

}

void loop() {
  humidity = (dht14.readHumidity());
  temperature = (dht14.readTemperature());
  lcd.setCursor(0,0);
  lcd.print("Hum: " + String(humidity) + " %");
  lcd.setCursor(0, 1);
  lcd.print("Temp: " + String(temperature) + " C");
  delay(100);
}
