#include "Car.h"
#include "Flasher.h"
#include "choumpa.h"

Flasher interver1(12,1000,5000);

void setup() {
  pwd_setup();
  CarInit();
  Init_Setup();
  Ultrasonicsetup();
}
void loop() {
 Car_loop(Sensor_Loop());
 /* 초음파 센서로 비상정지 기능 적용하기 */
 Serial.println(UltrasonicSensor());
}
