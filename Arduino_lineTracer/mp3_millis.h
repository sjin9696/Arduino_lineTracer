#ifndef mp3_millis_h
#define mp3_millis_h

#define RX 2
#define TX 3
#include <SoftwareSerial.h>
#include <DFRobotDFPlayerMini.h>

#include "Arduino.h"
class mp3Class {
  int ledPin;
  long OnTime;
  long OffTime;
  int ledState;
  unsigned long previousMillis;
  public:mp3Class();
  public:SetMp3Class(int volumeValue, long on, long off);
  public:void Update();
};
void setup_mp3();
#endif
