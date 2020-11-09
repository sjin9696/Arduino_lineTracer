#include "Car.h"
#include "Flasher.h"
#include "choumpa.h"
#include "RGBColorSensor.h"
#include "MP3.h"

Flasher interver1(12, 1000, 5000);

void setup() {
  pwd_setup();
  CarInit();
  Init_Setup();
  Ultrasonicsetup();
//  RGBsensor_setup() ;
//  MP3setup(30);

}
void loop() {
  pwd_loop();
  

  
}
