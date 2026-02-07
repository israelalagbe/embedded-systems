#pragma once

#include "Pin.h";

class TrafficLight {
  private:
    const Pin pins[3];
    int index = 0;
    const int maxIndex = 3;
  public:
    TrafficLight(Pin redPin, Pin bluePin, Pin greenPin);
    void nextLight();
};