#include "analog_sensor.h"

int Analog_Sensor(void* pin) {
  int val = analogRead(pin);
  return map(val,0,1023,0,255);
}// void loop() 끝
