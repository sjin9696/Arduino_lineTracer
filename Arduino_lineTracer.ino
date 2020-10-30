#include "IR_sensor.h"
#include "Car.h"
#include "BT.h"

void setup() {
  pwd_setup();
  CarInit();
  Init_Setup();
}

void loop() {
  String result = Sensor_Loop();
  Car_loop(result);
  
  if(pwd_loop()=='1'){
    
   Car_loop("1001 라인전진");
   delay(1000);
  }
  else{
    Car_loop("0000 전부 검은색 정지! ");
    delay(1000);
  }
}
