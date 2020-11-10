#include "mp3_millis.h"

SoftwareSerial MP3Module(TX, RX);
DFRobotDFPlayerMini MP3Player;

mp3Class::mp3Class() { //생성자
  
}

mp3Class::SetMp3Class(int volumeValue, long on, long off) {
  setup_mp3();
  MP3Player.volume(volumeValue);  // 볼륨을 조절합니다. 0~30까지 설정이 가능합니다.
  OnTime = on;
  OffTime = off;
  ledState = LOW;
  previousMillis = 0;
}

void mp3Class::Update() {
  unsigned long currentMillis = millis();
  if ((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
  {
    ledState = LOW;
    previousMillis = currentMillis;
    //digitalWrite(ledPin, ledState);
  }
  else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
  {
    MP3Player.play(rand() % 6);
    ledState = HIGH;
    previousMillis = currentMillis;
    //digitalWrite(ledPin, ledState);
  }
}

void setup_mp3() {
  Serial.begin(9600);
  MP3Module.begin(9600);
  if (!MP3Player.begin(MP3Module)) { // MP3 모듈을 초기화합니다. 초기화에 실패하면 오류를 발생시킵니다.
    Serial.println(F("Unable to begin:"));
    Serial.println(F("1.Please recheck the connection!"));
    Serial.println(F("2.Please insert the SD card!"));
    while (true);
  }
}
