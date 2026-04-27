#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <DHT.h>

// --- Configuration ---
#define DHTPIN 2            // DHT11 Data pin
#define DHTTYPE DHT11
#define RELAY_PIN 8         // Signal pin for HW-482 Relay
#define TEMP_THRESHOLD 32.0 // Turn-On temperature

// --- Objects ---
DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  dht.begin();
  
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, LOW); // Fan starts OFF
  
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("Group 1 Project");
  lcd.setCursor(0, 1);
  lcd.print("Greenhouse Ready");
  
  delay(2000);
  lcd.clear();
}

void loop() {
  delay(2000); // DHT11 minimum sampling interval
  
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  
  if (isnan(h) || isnan(t)) {
    lcd.setCursor(0, 0);
    lcd.print("Sensor Error!   ");
    return;
  }
  
  // --- Display Data ---
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(t);
  lcd.print(" C");
  
  lcd.setCursor(0, 1);
  lcd.print("Hum:  ");
  lcd.print(h);
  lcd.print(" %");
  
  // --- Relay Logic ---
  if (t > TEMP_THRESHOLD) {
    digitalWrite(RELAY_PIN, HIGH); // Fan ON
    Serial.println("THRESHOLD REACHED: Relay Clicked ON");
  } else {
    digitalWrite(RELAY_PIN, LOW);  // Fan OFF
    Serial.println("TEMP NORMAL: Relay Clicked OFF");
  }
}
