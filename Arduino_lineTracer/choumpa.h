#ifndef CHOUMPA_H
#define CHOUMPA_H

void Ultrasonicsetup();
float UltrasonicSensor();

class choumpa {
  int ledPin;
  long OnTime;
  long OffTime;
  int ledState;
  float duration;
  public: float distance;
  unsigned long previousMillis;
  public:choumpa(int pin, long on, long off);
  public:void Update();
};

#endif
