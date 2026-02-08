#include <Arduino.h>
#include <Pin.h>
#include <TrafficLight.h>

const int redLed = 6;
const int yellowLed = 5;
const int greenLed = 4;

Pin red(redLed, OUTPUT, "RED");
Pin yellow(yellowLed, OUTPUT, "YELLOW");
Pin green(greenLed, OUTPUT, "GREEN");

TrafficLight trafficLight(red, yellow, green);

const unsigned long int timeout = 10000; //  10 seconds(s)

void setup()
{
  Serial.begin(9600);
}

void loop()
{
  delay(timeout);
  trafficLight.nextLight();
}