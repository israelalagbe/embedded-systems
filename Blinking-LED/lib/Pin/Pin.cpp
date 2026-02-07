#include "Pin.h"
#include <Arduino.h>

Pin::Pin(const unsigned long int number, const unsigned long int mode): number(number), mode(mode)
{ 
  pinMode(number, mode);
}

void Pin::turnOn() const
{
  digitalWrite(number, HIGH);
}

void Pin::turnOff() const
{
  digitalWrite(number, LOW);
}