#ifndef BT_h
#define BT_h

#include <SoftwareSerial.h>
#include "Arduino.h"

void pwd_setup();
void pwd_loop();
void Control_Car(int val);
void BT_Check_Car_act(char c, int command);
void Sensor_Control_Car(int val);
void Sensor_Check_Car_act(char c, int command);
#endif
