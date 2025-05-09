#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Clock {
  bool noon = false;
  int hours = 10;
  int minutes = 0;
  int seconds = 0;


private:
  void tickHour() {
    if (hours >= 12) {
      hours = 1;
    }

    hours += 1;
  }

  void tickMinute() {
    if (minutes >= 60) {
      minutes = 0;
      tickHour();
    }
    minutes += 1;
  }

  void tickSecond() {
    if (seconds >= 60) {
      seconds = 0;
      tickMinute();
    }
    seconds++;
  }

public:
  Clock() {
  }

  tick() {
    tickSecond();
  }

  String getTime() {
    char buffer[20];
    sprintf(buffer, "%02d:%02d:%02d %s", hours, minutes, seconds, noon ? "PM" : "AM");
    return String(buffer);
  }
};

// Set the LCD address (usually 0x27 or 0x3F) and dimensions (16 rows, 2 columns)
LiquidCrystal_I2C lcd(0x27, 16, 2);

Clock clock;

void setup() {
  Serial.begin(38400);

  lcd.init();
  lcd.backlight();
}


void loop() {
  lcd.clear();
  // row,column
  lcd.setCursor(2, 1);
  lcd.print(clock.getTime());

  clock.tick();
  delay(1000);
}