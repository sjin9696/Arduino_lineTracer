#include "BT.h"
#include "Car.h"
#include "choumpa.h"

choumpa choumpa(11, 1, 1000);

SoftwareSerial BTSerial(2, 3);
char nowBT;
char lastBT;
float distance_ultra = 15.00;

void pwd_setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  BTSerial.begin(9600);
  pinMode(13, OUTPUT);

}

void pwd_loop() {
  choumpa.Update();
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
    if (choumpa.distance >= distance_ultra) {
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
          choumpa.Update();
          if (choumpa.distance >= distance_ultra) {
            Serial.println("distance" + (String)choumpa.distance);
            Controler(FRONT);
            Serial.println("전진");
          }
          else {
            Stop();
          }
        }
        break;
      case 'd': // 후진
        while (BTSerial.read() != 'D') {
          choumpa.Update();
          if (choumpa.distance >= distance_ultra) {
            Controler(BACK);
            Serial.println("후진");
          }
          else {
            Stop();
          }
        }
        break;
      case 'r': // 좌회전
        while (BTSerial.read() != 'R') {
          choumpa.Update();
          if (choumpa.distance >= distance_ultra) {
            Controler(LEFT);
            Serial.println("좌회전");
          }
          else {
            Stop();
          }
        }
        break;
      case 'l': //우회전
        while (BTSerial.read() != 'L') {
                    choumpa.Update();
          if (choumpa.distance >= distance_ultra) {
            Controler(RIGHT);
            Serial.println("우회전");
          }
          else {
            Stop();
          }
        }
        break;
    }
  }
  nowBT = 'c';
  Stop();
}
