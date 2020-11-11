#ifndef IR_sensor_h
#define IR_sensor_h

#include "Arduino.h"

#define LINE_IN 1
#define LINE_OUT 0

#define SERIAL_MONITOR 9600
#define SENSOR_EA 3

void Init_Setup() ;
char Sensor_Loop() ;
char Sensor_Result() ;
#endif
