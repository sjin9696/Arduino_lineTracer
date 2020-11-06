#include "Car.h"
#include "Flasher.h"

Flasher interver1(12,1000,5000);

void setup() {
  pwd_setup();
  CarInit();
  Init_Setup();
}
void loop() {
 Car_loop(Sensor_Loop());
}
