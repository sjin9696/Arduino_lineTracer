#ifndef Flasher_h
#define Flasher_h

#include "Arduino.h"

class Flasher {
  int ledPin;
  long OnTime;
  long OffTime;
  int ledState;
  unsigned long previousMillis;
  public:Flasher(int pin, long on, long off);
  public:void Update();
};
#endif
