#include "BT.h"
#include "Car.h"

SoftwareSerial BTSerial(2,3);

void pwd_setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(13,OUTPUT);
}

String pwd_loop() {
//  // put your main code here, to run repeatedly:
//  if(BTSerial.available()){
//    char data = BTSerial.read();
//
//    if(data =='t'){ //front
//      Car_loop("1001 라인전진");
//      Serial.println("1001 라인전진");
//    }
//    if(data == 'g'){//back
//      Car_loop("1001 라인전진");
//      return "뒤로 BACK";
//    }
//    if(data == 'f'){//left
//      return "1011 라인살짝벗어남 왼쪽";
//    }
//    if(data == 'h'){//right
//      return "1100 라인살짝벗어남 오른쪽";
//    }
//    if(data == 'p'){//stop
//      return "0000 전부 검은색 정지! ";
//    }
//    if(data == 's'){//stop
//      return "자동주행";
//    }
//  }
//
//  if(Serial.available()){
//    BTSerial.write(Serial.read());
//  }
// //return "def";
}
