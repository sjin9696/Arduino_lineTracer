#include "libTest.h"
#include "Car.h"


void setup() {
  Serial.begin(9600);
 
  CarInit();
  Init_Setup();
}

void loop() {
  String result = Sensor_Loop();
  Car_loop(result);
}
