#include "BT.h"
#include "Car.h"
#include "choumpa.h"
#include "servo_rift_ing.h"
#include "RGBColorSensor.h"

choumpa choumpa(11, 1, 10); // new choumpa(); 인스턴스만들어서

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
  choumpa.Update(); //갱신

  // put your main code here, to run repeatedly:
  if (BTSerial.available()) {
    //Serial.println("들어오나?");
    Serial.print("nowBT : ");
    Serial.print(nowBT);
    Serial.print("  lastBT : ");
    Serial.println(lastBT);
    nowBT = BTSerial.read();
    if (nowBT == 'a' || nowBT == 'c') {
      lastBT = nowBT;
    }
  }
  if (lastBT == 'a') {
    while (Sensor_Loop() != 'u') {
      choumpa.Update();
      if (RGBsensor_loop() == "Blue")
      {
        RiftUp();
      }
      else if (RGBsensor_loop() == "Red")
      {
        RiftDown();
      }
      if (choumpa.distance >= distance_ultra) {
        if (Sensor_Loop() == 'u') {
          break;
        }
        if (Sensor_Loop() == 'l') {
          Left();
        }
        else if (Sensor_Loop() == 'r') {
          Right();
        }
      }
      else {
        Stop();
      }
    }
    while (Sensor_Loop() == 'u') {
      if (RGBsensor_loop() == "Blue")
      {
        RiftUp();
      }
      else if (RGBsensor_loop() == "Red")
      {
        RiftDown();
      }
      choumpa.Update();
      if (choumpa.distance >= distance_ultra) {
        Front();
      }
      else {
        Stop();
      }
      if (Sensor_Loop() == 'r' || 'l') {
        break;
      }
    }
    nowBT = lastBT;
  }
  else if (lastBT == 'c') {
    //Serial.println("수동");
    Stop();
    Control_Car(nowBT);
    nowBT = 'c';
  }
  //Stop();
}

void Control_Car(int val) {
  switch (nowBT) {
    case 'u': // 전진
      BT_Check_Car_act('U', FRONT);
      break;
    case 'd': // 후진
      BT_Check_Car_act('D', BACK);
      break;
    case 'r': // 좌회전
      BT_Check_Car_act('R', LEFT);
      break;
    case 'l': //우회전
      BT_Check_Car_act('L', RIGHT);
      break;
    case 'z': // 리프트업
      RiftUp();
      Serial.println("리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업리프트업");
      break;
    case 'x': // 리프트 다운
      RiftDown();
      break;
  }
}
void BT_Check_Car_act(char c, int command) {
  while (BTSerial.read() != c) {
    choumpa.Update();
    if (choumpa.distance >= distance_ultra)
      Controler(command);
    else
      Stop();
  }
}

void Sensor_Control_Car(int val) {
  switch (nowBT) {
    case 'u': // 전진
      Sensor_Check_Car_act('u', FRONT);
      break;
    case 'd': // 후진
      Sensor_Check_Car_act('d', BACK);
      break;
    case 'r': // 좌회전
      Sensor_Check_Car_act('r', LEFT);
      break;
    case 'l': //우회전
      Sensor_Check_Car_act('l', RIGHT);
      break;
  }
}
void Sensor_Check_Car_act(char c, int command) {
  while (Sensor_Loop() != c) {
    choumpa.Update();
    if (choumpa.distance >= distance_ultra)
      Controler(command);
    else
      Controler(FRONT);
  }
}
