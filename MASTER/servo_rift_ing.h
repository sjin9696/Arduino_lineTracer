#include <Servo.h>
#include "Arduino.h"

#ifndef ServoRifting_H
#define ServoRifting_H

#define SERVO_PIN  8
#define DOWN_ANGLE 0
#define UP_ANGLE   70

void RiftSetup();
void RiftUp();
void RiftDown();
bool getRiftState();

#endif
