#include "Car.h"
#include "Timer.h"
#include "Flasher.h"

const int LED1_8 = 8;                    //connect one LED to this pin (with appropriate current-limiting resistor of course)
const int LED2 = 9;                    //connect another LED to this pin (don't forget the resistor)
const unsigned long PERIOD1000 = 1000;    //one second
const unsigned long PERIOD2 = 10000;   //ten seconds
Timer left;
Timer right;

Flasher led1(11,100,400);
Flasher led2(12,350,350);

void setup() {
  pwd_setup();
  CarInit();
  Init_Setup();
 
}

void loop() {
  led1.Update();
  led2.Update();
  left.update();
  right.update();
  //Car_loop("1001 라인전진");
  Serial.print("LEFT : ");Serial.print(Analog_Sensor(LEFT_PIN_A5));
  Serial.print(" RIGHT : ");Serial.println(Analog_Sensor(RIGHT_PIN_A4));
  int val_L = Analog_Sensor(LEFT_PIN_A5);
  int val_R = Analog_Sensor(RIGHT_PIN_A4);
  
  if(val_R >0){
    Right_Front();
     if(val_R > 50){
      Controler(STOP);
      right.every(val_R,readData_Right);
    }
  }
  if(val_L >0){
      Controler(STOP);
     if(val_L > 50){
      Left_Front();
      left.every(val_L,readData_Left);
    }
  }
  
  Controler(STOP);
}

void readData_Right(){
  int val_R = Analog_Sensor(RIGHT_PIN_A4);
   Serial.print(" RIGHT : ");Serial.print(val_R);
  if(val_R >0){
    Right_Front();
     if(val_R > 50){
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
      left.every(val_L*2,readData_Left);
    }
  }
  return 0;
}
