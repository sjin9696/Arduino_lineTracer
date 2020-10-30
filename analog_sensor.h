#ifndef analog_sensor_h
#define analog_sensor_h

#include "Arduino.h"

#define RIGHT_PIN_A4 A4
#define LEFT_PIN_A5  A5

#define serialMonitor 9600

int Analog_Sensor_Loop();
int Analog_Sensor(void* pin);
#endif
