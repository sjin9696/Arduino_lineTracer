#include "RGBColorSensor.h"
void setup() {
  RGBsensor_setup();
}

void loop() {
  String result = RGBsensor_loop();
  Serial.println(result);
}
