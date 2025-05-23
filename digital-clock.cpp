#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

class Clock {
private:
  bool noon = false;  // false = AM, true = PM

  // I'm currently using a static date, but it can be replaced with a real-time clock (RTC) module 
  // that includes a CMOS battery to maintain accurate date and time even when the device is powered off
  int hours = 10;
  int minutes = 0;
  int seconds = 0;
  int day = 18;
  int month = 5;
  int year = 2025;

  // Days in each month (non-leap year)
  int daysInMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

  bool isLeapYear() {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
  }

  void updateLeapYear() {
    daysInMonth[1] = isLeapYear() ? 29 : 28;
  }

  void tickHour() {
    hours += 1;
    if (hours > 12) {
      hours = 1;
    }
    if (hours == 12) {
      noon = !noon;  // Toggle AM/PM at 12
    }
    if (hours == 12 && !noon) {
      tickDay();  // Advance day after 11:59 PM -> 12:00 AM
    }
  }

  void tickMinute() {
    minutes += 1;
    if (minutes >= 60) {
      minutes = 0;
      tickHour();
    }
  }

  void tickSecond() {
    seconds += 1;
    if (seconds >= 60) {
      seconds = 0;
      tickMinute();
    }
  }

  void tickDay() {
    day += 1;
    if (day > daysInMonth[month - 1]) {
      day = 1;
      tickMonth();
    }
  }

  void tickMonth() {
    month += 1;
    if (month > 12) {
      month = 1;
      tickYear();
    }
  }

  void tickYear() {
    year += 1;
    updateLeapYear(); 
  }

public:
  Clock() {
    updateLeapYear(); 
  }

  void tick() {
    tickSecond();
  }

  String getDate() {
    char dateBuffer[30];
    sprintf(dateBuffer, "%02d/%02d/%04d", day, month, year);
    return String(dateBuffer);
  }

  String getTime() {
    char timeBuffer[20];
    sprintf(timeBuffer, "%02d:%02d:%02d %s", hours, minutes, seconds, noon ? "PM" : "AM");
    return String(timeBuffer);
  }

  String getDateTime() {
    return getDate() + " " + getTime();
  }

  String getTimeOfDay() {
    int hour24 = hours % 12 + (noon ? 12 : 0); // Convert to 24-hour format

    if (hour24 >= 5 && hour24 < 12) {
      return "morning";
    } else if (hour24 >= 12 && hour24 < 17) {
      return "afternoon";
    } else if (hour24 >= 17 && hour24 < 21) {
      return "evening";
    } else {
      return "night";
    }
  }
};

// Set the LCD address (usually 0x27 or 0x3F) and dimensions (16 rows, 2 columns)
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
