#include "Pin.h";
#include "TrafficLight.h"

TrafficLight::TrafficLight(Pin red, Pin blue, Pin green): pins{ red, green, blue } {
  red.turnOn();
};

void TrafficLight::nextLight() {
  this->pins[this->index].turnOff();
  this->index = (++index) % this->maxIndex;
  this->pins[this->index].turnOn();
}