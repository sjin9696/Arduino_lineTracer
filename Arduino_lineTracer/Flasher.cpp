#include "Flasher.h"
  Flasher::Flasher(int pin, long on, long off){
    ledPin = pin;
    //pinMode(ledPin,OUTPUT);
    MP3Play(3);
    
    OnTime = on;
    OffTime = off;
    ledState = LOW;
    previousMillis = 0;
  }
  //millis()를 이용해 입력한 시간 동안 호출해서 동작하는 함수 반환값은 bool타입으로 사용시 조건문 이용.
  //1회성 조건.
//  bool Flasher::DoIt(unsigned long time_){
//    method();
//    unsigned long currentMillis = millis();
//    if(currentMillis - previousmillis >= time_){
//      
//      return true;
//    }
//  }

  void Flasher::Update(){
    unsigned long currentMillis = millis();
    if((ledState == HIGH) && (currentMillis - previousMillis >= OnTime))
    {
      Serial.println();
      ledState = LOW;
      previousMillis = currentMillis;
//      digitalWrite(ledPin, ledState);
    }
    else if ((ledState == LOW) && (currentMillis - previousMillis >= OffTime))
    {
      ledState = HIGH;
      previousMillis = currentMillis;
//      digitalWrite(ledPin, ledState);
    }
  }
