#ifndef libTest_h
#define libTest_h

#define LINE_IN 1
#define LINE_OUT 0

#define serialMonitor 9600
#define sensor_EA 4

String sensor_print(int num,int *val);
bool Line(int n);
String Result_Print(int *A);
void Init(int *A);
void Init_Setup();
String Sensor_Loop();

#endif
