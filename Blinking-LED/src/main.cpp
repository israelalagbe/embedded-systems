#include <Arduino.h>
#include "Pin.h"

Pin ledPin(LED_BUILTIN, OUTPUT);

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("Turning on LED...");

  ledPin.turnOn();
  delay(1000); // Wait for 1 second

  Serial.println("Turning off LED...");

  ledPin.turnOff();
  delay(1000); // Wait for 1 second
}
