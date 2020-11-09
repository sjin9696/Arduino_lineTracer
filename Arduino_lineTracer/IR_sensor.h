#ifndef IR_sensor_h
#define IR_sensor_h

#include "Arduino.h"

#define serialMonitor 9600
#define sensor_EA 2

void Init(int *A);
void Init_Setup();
void Result_Print(int *A);
String Sensor_Loop();

#endif
