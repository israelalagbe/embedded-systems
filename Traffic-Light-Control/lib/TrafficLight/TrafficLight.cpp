#include "Pin.h"
#include "TrafficLight.h"

TrafficLight::TrafficLight(Pin &red, Pin &yellow, Pin &green)
{
  redNode.pin = &red;
  redNode.next = &yellowNode;
  yellowNode.pin = &yellow;
  yellowNode.next = &greenNode;
  greenNode.pin = &green;
  greenNode.next = &redNode; // circular linked list data structure
  cursor = &redNode;
  cursor->pin->turnOn();
}

void TrafficLight::nextLight()
{
  cursor->pin->turnOff();
  cursor = cursor->next;
  cursor->pin->turnOn();
}