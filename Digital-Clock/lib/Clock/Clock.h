#pragma once

#include <Arduino.h>

class Clock {
private:
  bool noon;  // false = AM, true = PM

  // Static date/time state (can be replaced with an RTC later)
  int hours;
  int minutes;
  int seconds;
  int day;
  int month;
  int year;

  // Days in each month (non-leap year)
  int daysInMonth[12];

  bool isLeapYear();
  void updateLeapYear();

  void tickHour();
  void tickMinute();
  void tickSecond();
  void tickDay();
  void tickMonth();
  void tickYear();

public:
  Clock();

  void tick();

  String getDate();
  String getTime();
  String getDateTime();
  String getTimeOfDay();
};
