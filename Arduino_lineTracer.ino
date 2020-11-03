#include "Car.h"

void setup() {
  pwd_setup();
  CarInit();
  Init_Setup();
}

void loop() {
  String sensor = Sensor_Loop();
  Car_loop(sensor);
}
