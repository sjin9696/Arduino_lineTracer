#include "servo_rift_ing.h"

Servo servo;
int servoPin;
bool riftState;

void RiftSetup(){
  servoPin = SERVO_PIN;
  riftState = false;
  servo.attach(SERVO_PIN); 
  servo.write(DOWN_ANGLE);
}

void RiftUp(){
  if(riftState == false){
    servo.write(UP_ANGLE);
    riftState = true;
  }
}

void RiftDown(){
    if(riftState == true){
    servo.write(DOWN_ANGLE);
    riftState = false;
  }
}

bool getRiftState(){
  return riftState;
}
