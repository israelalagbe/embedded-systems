#include "Pin.h"
#include <Arduino.h>

Pin::Pin(const unsigned long int number, const unsigned long int mode, const char * name): number(number), mode(mode), name(name)
{ 
  pinMode(number, mode);
}

void Pin::turnOn() const
{
  digitalWrite(number, HIGH);
  Serial.print("Turn ON: ");
  if (name) Serial.println(name);
  else { Serial.print("Pin "); Serial.println(number); }
}

void Pin::turnOff() const
{
  digitalWrite(number, LOW);
  Serial.print("Turn OFF: ");
  if (name) Serial.println(name);
  else { Serial.print("Pin "); Serial.println(number); }
} 