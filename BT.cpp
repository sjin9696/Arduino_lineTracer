#include <SoftwareSerial.h>
#include "Arduino.h"
#include "BT.h"

SoftwareSerial BTSerial(2,3);

void pwd_setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(13,OUTPUT);
}

char pwd_loop() {
  // put your main code here, to run repeatedly:
  if(BTSerial.available()){
    char data = BTSerial.read();
    Serial.write(data);

    if(data =='1'){
      digitalWrite(13,HIGH);
      return '1';
    }
    if(data == '0'){
      digitalWrite(13,LOW);
      return '0';
    }
  }

  if(Serial.available()){
    BTSerial.write(Serial.read());
  }
  return '2';
}
