#include "Car.h"
#include "Timer.h"
const int LED1_8 = 8;                    //connect one LED to this pin (with appropriate current-limiting resistor of course)
const int LED2 = 9;                    //connect another LED to this pin (don't forget the resistor)
const unsigned long PERIOD1000 = 1000;    //one second
const unsigned long PERIOD2 = 10000;   //ten seconds
Timer left;
Timer right;

void setup() {
  pwd_setup();
  CarInit();
  Init_Setup();
  left.every(100,readData_Left);
  right.every(100,readData_Right);
}

void loop() {
  left.update();
  right.update();
  //Car_loop("1001 라인전진");
  //Serial.print("LEFT : ");Serial.print(Analog_Sensor(LEFT_PIN_A5));
  //Serial.print(" RIGHT : ");Serial.println(Analog_Sensor(RIGHT_PIN_A4));
  /*int val_L = Analog_Sensor(LEFT_PIN_A5);
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
  */
}

void readData_Right(){
 
  int val_R = Analog_Sensor(RIGHT_PIN_A4);
   Serial.print(" RIGHT : ");Serial.print(val_R);
  if(val_R >0){
    Right_Front();
     if(val_R > 50){
      Controler(STOP);
      right.every(val_R*2,readData_Right);
    }
  }
  return 0;
}
void readData_Left(){
 
  int val_L = Analog_Sensor(LEFT_PIN_A5);
   Serial.print(" Left : ");Serial.println(val_L);
  if(val_L >0){
    Left_Front();
     if(val_L > 50){
      Controler(STOP);
      left.every(val_L*2,readData_Left);
    }
  }
  return 0;
}
