#ifndef IR_sensor_h
#define IR_sensor_h

#include "Arduino.h"

#define FRONT 'f'
#define STOP  's'
#define BACK  'b'
#define RIGHT 'r'
#define LEFT  'l'

#define LINE_IN 1
#define LINE_OUT 0

#define serialMonitor 9600
#define sensor_EA 4

//라인 전진 중에 값이 읽히면.. 작업을 진행. 
void Result_Print(int *A);
void Init(int *A);
void Init_Setup();
String Sensor_Loop();
#endif
