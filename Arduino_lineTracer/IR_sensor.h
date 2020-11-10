#ifndef IR_sensor_h
#define IR_sensor_h

#include "Arduino.h"

#define LINE_IN 1
#define LINE_OUT 0

#define SERIAL_MONITOR 9600
#define SENSOR_EA 2

//라인 전진 중에 값이 읽히면.. 작업을 진행. 
void Result_Print(int *A);
void Init(int *A);
void Init_Setup();
char Sensor_Loop();
char Sensor_Result(String result);
#endif
