#include "servo_rift_ing.h"

void setup() 
{ 
  RiftSetup();
} 

void loop() 
{ 
  bool Rift = getRiftState();
  RiftDown();
} 
