#include "servo_rift_ing.h"

#include "Car.h"

Servo servo;
int servoPin;
bool riftState;

void RiftSetup() {
  servoPin = SERVO_PIN;
  riftState = false;
  servo.attach(SERVO_PIN);
  servo.write(DOWN_ANGLE);
}

void RiftUp() {
  if (riftState == false) {
    Stop();
    delay(1000);
    servo.write(UP_ANGLE);
    delay(2000);
    riftState = true;
  }
}

void RiftDown() {
  if (riftState == true) {
    Stop();
    delay(1000);
    servo.write(DOWN_ANGLE);
    delay(2000);
    riftState = false;
  }
}

bool getRiftState() {
  return riftState;
}
