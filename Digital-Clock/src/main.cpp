#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "Clock.h"

// Set the LCD address (usually 0x27 or 0x3F) and dimensions (16 columns, 2 rows)
LiquidCrystal_I2C lcd(0x27, 16, 2);

Clock clock;

void setup() {
  Serial.begin(38400);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0, 0);
  lcd.print("Good " + clock.getTimeOfDay() + ", ");
  lcd.setCursor(10, 1);
  lcd.print("Israel");
  delay(3000);
}

void loop() {
  lcd.clear();
  // row,column
  lcd.setCursor(0, 0);
  lcd.print(clock.getDate());

  lcd.setCursor(5, 1);
  lcd.print(clock.getTime());

  clock.tick();
  delay(1000);
}