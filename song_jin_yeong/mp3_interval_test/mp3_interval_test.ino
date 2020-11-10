#include "mp3_millis.h"
#include "Flasher.h"
Flasher led(8,50,50);
mp3Class mp3;

void setup() {
  mp3.SetMp3Class(20, 3000, 1000);
}

void loop() {
  mp3.Update();
  led.Update();
}
