#ifndef Car_h
#define Car_h

#include "Arduino.h"
#include "IR_sensor.h"
#include "BT.h"
#include "analog_sensor.h"

#define Right_Plus  4
#define Right_Minus 5
#define Left_Plus   6
#define Left_Minus  7

#define Right_PWM 9
#define Left_PWM  10

#define STOP  000
#define FRONT 111
#define BACK  222
#define RIGHT 333
#define LEFT  444

void CarInit();
void Right_Stop();
void Left_Stop();
void Right_Front();
void Left_Front();
void Right_Back();
void Left_Back();
void Stop();
void Front();
void Back();
void Left();
void Right();
void Controler(int n_commend);
void Car_loop(String result);
#endif
