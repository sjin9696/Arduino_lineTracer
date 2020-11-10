#include "Car.h"
#include "Flasher.h"
#include "choumpa.h"
#include "RGBColorSensor.h"
#include "MP3.h"
#include "servo_rift_ing.h"
#include "RGBColorSensor.h"

Flasher interver1(12, 1000, 5000);

void setup() {
  pwd_setup();
  CarInit();
  Init_Setup();
  Ultrasonicsetup();
  RiftSetup();
  RGBsensor_setup() ;
//  MP3setup(30);

}
void loop() {
  pwd_loop();
}
// 1. 차량 주행 테스트,
// 2. 차량 블루투스 테스트
// 3. 초음파신호 테스트
// 4. 스피커 테스트
// 5. RGB확인 리프트 테스트
