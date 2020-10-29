#include "libTest.h"
#include "Car.h"

#define Right_Plus  4
#define Right_Minus 5
#define Left_Plus   6
#define Left_Minus  7

#define STOP  000
#define FRONT 111
#define BACK  222
#define RIGHT 333
#define LEFT  444

void setup() {
  Serial.begin(9600);
  CarInit();
  Init_Setup();
}

void loop() {
  String result = Sensor_Loop();
  Car_loop(result);
}
