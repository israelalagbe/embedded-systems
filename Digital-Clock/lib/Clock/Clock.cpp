#include "Clock.h"

Clock::Clock()
  : noon(false), hours(10), minutes(0), seconds(0), day(18), month(5), year(2025), daysInMonth{31,28,31,30,31,30,31,31,30,31,30,31}
{
  updateLeapYear();
}

bool Clock::isLeapYear() {
  return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

void Clock::updateLeapYear() {
  daysInMonth[1] = isLeapYear() ? 29 : 28;
}

void Clock::tickHour() {
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

void Clock::tickMinute() {
  minutes += 1;
  if (minutes >= 60) {
    minutes = 0;
    tickHour();
  }
}

void Clock::tickSecond() {
  seconds += 1;
  if (seconds >= 60) {
    seconds = 0;
    tickMinute();
  }
}

void Clock::tickDay() {
  day += 1;
  if (day > daysInMonth[month - 1]) {
    day = 1;
    tickMonth();
  }
}

void Clock::tickMonth() {
  month += 1;
  if (month > 12) {
    month = 1;
    tickYear();
  }
}

void Clock::tickYear() {
  year += 1;
  updateLeapYear();
}

void Clock::tick() {
  tickSecond();
}

String Clock::getDate() {
  char dateBuffer[30];
  sprintf(dateBuffer, "%02d/%02d/%04d", day, month, year);
  return String(dateBuffer);
}

String Clock::getTime() {
  char timeBuffer[20];
  sprintf(timeBuffer, "%02d:%02d:%02d %s", hours, minutes, seconds, noon ? "PM" : "AM");
  return String(timeBuffer);
}

String Clock::getDateTime() {
  return getDate() + " " + getTime();
}

String Clock::getTimeOfDay() {
  int hour24 = hours % 12 + (noon ? 12 : 0); // Convert to 24-hour format

  if (hour24 >= 5 && hour24 < 12) {
    return String("morning");
  } else if (hour24 >= 12 && hour24 < 17) {
    return String("afternoon");
  } else if (hour24 >= 17 && hour24 < 21) {
    return String("evening");
  } else {
    return String("night");
  }
}
