#include "MP3.h"
//#include <SoftwareSerial.h>
//#include <DFRobotDFPlayerMini.h>
//SoftwareSerial MP3Module(2, 3);
//DFRobotDFPlayerMini MP3Player;
void setup () {
  MP3setup(25);  
//  Serial.begin (9600);
//  MP3Module.begin(9600);
//  if (!MP3Player.begin(MP3Module)) { // MP3 모듈을 초기화합니다. 초기화에 실패하면 오류를 발생시킵니다.
//    Serial.println(F("Unable to begin:"));
//    Serial.println(F("1.Please recheck the connection!"));
//    Serial.println(F("2.Please insert the SD card!"));
//    while (true);
//  }
//  delay(1);
//  MP3Player.volume(30);  // 볼륨을 조절합니다. 0~30까지 설정이 가능합니다.
}

void loop () {
  MP3loop(3);
//  MP3Player.play(5);  // 0001.mp3를 재생합니다.
//  delay (3000);
}
