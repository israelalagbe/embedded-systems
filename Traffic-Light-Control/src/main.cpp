#include <Arduino.h>
#include <Pin.h>
#include <TrafficLight.h>


const int redLed = 6;
const int yellowLed = 5;
const int greenLed = 4;

TrafficLight trafficLight(Pin(redLed), Pin(yellowLed), Pin(greenLed));

const unsigned long int timeout = 3000; //  3 seconds(s)

void setup()
{
  // pinMode(redLed, OUTPUT);
  // pinMode(yellowLed, OUTPUT);
  // pinMode(greenLed, OUTPUT);
}

void loop()
{
  delay(timeout); 
  trafficLight.nextLight();
}