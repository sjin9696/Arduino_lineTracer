#ifndef Car_h
#define Car_h

#include "Arduino.h"
#include "IR_sensor.h"
#include "BT.h"

#define Right_Plus  5
#define Right_Minus 4
#define Left_Plus   7
#define Left_Minus  6

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
void Auto_Car_loop(String result);
#endif
