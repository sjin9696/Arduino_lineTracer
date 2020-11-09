#include "BT.h"
#include "Car.h"
#include "choumpa.h"

SoftwareSerial BTSerial(2, 3);
char nowBT;
char lastBT;

void pwd_setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(13, OUTPUT);
}

void pwd_loop() {
  // put your main code here, to run repeatedly:
  if (BTSerial.available()) {
    Serial.println("들어오나?");
    nowBT = BTSerial.read();
    Serial.println("nowBT : " + nowBT);
    if (nowBT == 'a' || nowBT == 'c') {
      lastBT = nowBT;
    }
  }
  if (lastBT == 'a') {
    if (UltrasonicSensor() >= 10.00) {
      Auto_Car_loop(Sensor_Loop());
      Serial.println("Auto");
    }
    else {
      Stop();
    }
  }
  else if (lastBT == 'c') {
    Serial.println("수동");
    Stop();
    switch (nowBT) {
      case 'u': // 전진
        while (BTSerial.read() != 'U') {
          if (UltrasonicSensor() >= 10.00) {
            Controler(FRONT);
            Serial.println("전진");
            delay(5);
          }
          else {
            Stop();
          }
        }
        break;
      case 'd': // 후진
        while (BTSerial.read() != 'D') {
          if (UltrasonicSensor() >= 10.00) {
            Controler(BACK);
            Serial.println("후진");
            delay(5);
          }
          else {
            Stop();
          }
        }
        break;
      case 'r': // 우회전
        while (BTSerial.read() != 'R') {
          if (UltrasonicSensor() >= 10.00) {
            Controler(RIGHT);
            Serial.println("우회전");
            delay(5);
          }
          else {
            Stop();
          }
        }
        break;
      case 'l': //좌회전
        while (BTSerial.read() != 'L') {
          if (UltrasonicSensor() >= 10.00) {
            Controler(LEFT);
            Serial.println("좌회전");
            delay(5);
          }
          else {
            Stop();
          }
        }
        break;
    }
  }
  nowBT = 'c';
  delay(100);
  Stop();
}
