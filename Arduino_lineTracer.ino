#include "Car.h"

void setup() {
  pwd_setup();
  CarInit();
  Init_Setup();
}

void loop() {
  //Car_loop("1001 라인전진");
  Serial.print("LEFT : ");Serial.print(Analog_Sensor(LEFT_PIN_A5));
  Serial.print(" RIGHT : ");Serial.println(Analog_Sensor(RIGHT_PIN_A4));
  int val_L = Analog_Sensor(LEFT_PIN_A5);
  int val_R = Analog_Sensor(RIGHT_PIN_A4);
  
  if(val_R >0){
    Right_Front();
     if(val_R > 2){
      Controler(STOP);
      delay((Analog_Sensor(RIGHT_PIN_A4)));
    }
  }
  if(val_L >0){
    Left_Front();
     if(val_L > 2){
      Controler(STOP);
      delay((Analog_Sensor(LEFT_PIN_A5)));
    }
  }
 
  
}
