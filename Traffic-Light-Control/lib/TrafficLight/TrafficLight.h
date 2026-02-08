#pragma once

#include "Pin.h"

struct PinNode{
  Pin * pin;
  PinNode* next;
};


class TrafficLight {
  private:
    PinNode redNode;
    PinNode yellowNode;
    PinNode greenNode;
    PinNode * cursor;
  public:
    TrafficLight(Pin &red, Pin &yellow, Pin &green);
    void nextLight();
};