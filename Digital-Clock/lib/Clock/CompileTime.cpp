#include "CompileTime.h"
#include <stdio.h>
#include <string.h>

CompileTime getCompileTime() {
  CompileTime compileTime{1970, 1, 1, 0, 0, 0};

  const char *cdate = __DATE__; // "Mmm dd yyyy"
  const char *ctime_s = __TIME__; // "HH:MM:SS"

  // Parse date
  char monStr[4] = {0};
  int dayParsed = 1, yearParsed = 1970;
  if (sscanf(cdate, "%3s %d %d", monStr, &dayParsed, &yearParsed) == 3) {
    compileTime.day = dayParsed;
    compileTime.year = yearParsed;
    const char *months[] = {"Jan","Feb","Mar","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"};
    compileTime.month = 1;
    for (int i = 0; i < 12; ++i) {
      if (strncmp(monStr, months[i], 3) == 0) { compileTime.month = i + 1; break; }
    }
  }

  // Parse time
  int hour24 = 0, minute24 = 0, second24 = 0;
  if (sscanf(ctime_s, "%d:%d:%d", &hour24, &minute24, &second24) == 3) {
    compileTime.hour = hour24;
    compileTime.minute = minute24;
    compileTime.second = second24;
  }

  return compileTime;
}
