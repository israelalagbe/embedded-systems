#pragma once

struct CompileTime {
  int year;
  int month;
  int day;
  int hour;
  int minute;
  int second;
};

CompileTime getCompileTime();
