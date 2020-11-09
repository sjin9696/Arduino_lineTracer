#include <SoftwareSerial.h>
#include "choumpa.h"
SoftwareSerial BTSerial(12, 13);     //(TX, RX) 번호

int motorPin[4] = {2, 3, 4, 7};    // motor 센서
int speedPin[2] = {5, 6};          // pwm 속력 제어
int irPin[4] = {8, 9, 10, 11};     // 적외선
//int trigPin = 15;                  // 초음파 센서
//int echoPin = 14;                  // 초음파 센서
int Speed = 140;                   // 최대 속도
int pSpeed = 0;                    // 현재 속도
char nowState;               // 회전 상태 DP
char nowBT;                  // 블루투스 처음 값 받기 상태 확인
char lastBT;                 // 블루투스 값 받기

// 오른쪽 바퀴 제어 속도 speedPin[0], 왼쪽 바퀴 제어 속도 speedPin[1]
// 오른쪽 바퀴 motorPin[0, 1], 왼쪽 바퀴 motorPin[2, 3]

//void leftMove();
//void stopMove();
//void rightMove();
//void straightMove();

void setup() {
  Serial.begin(9600);
  BTSerial.begin(9600);
  for (int i = 0 ; i < 4; i++) {
    pinMode(motorPin[i], OUTPUT);
  }
  for (int i = 0 ; i < 2; i++) {
    pinMode(speedPin[i], OUTPUT);
  }
  for (int i = 0 ; i < 4; i++) {
    pinMode(irPin[i], INPUT);
  }
  Ultrasonicsetup();

}

void loop() {
  // 블루투스 센서---------------------------------------------------------------------------------------------------------------------
  //blueTooth값 받기.
  if (BTSerial.available())
  {
    nowBT = BTSerial.read();//현재값을 nowBT에 저장
    Serial.print("뭐가왔는가");
    Serial.println(nowBT);
    if (nowBT == 'a' || nowBT == 'c')
    { //수동,자동일경우만 lastBT에 저장.
      lastBT = nowBT;
    }
  }
  if (lastBT == 'a') {
    if (UltrasonicSensor() >= 10.00) {
      AutoMove();
      Serial.println("Auto");
    }
    else {
      stopMove();
    }
  }
  else if (lastBT == 'c') {
    stopMove();
    switch (nowBT) {
      case 'u': // 전진
        while (BTSerial.read() != 'U') {
          if (UltrasonicSensor() >= 10.00) {
            straightMove();
            Serial.println("전진");
            delay(5);
          }
          else {
            stopMove();
          }
        }
        break;
      case 'd': // 후진
        while (BTSerial.read() != 'D') {
          if (UltrasonicSensor() >= 10.00) {
            backMove();
            Serial.println("후진");
            delay(5);
          }
          else {
            stopMove();
          }
        }
        break;
      case 'r': // 우회전
        while (BTSerial.read() != 'R') {
          if (UltrasonicSensor() >= 10.00) {
            rightMove();
            Serial.println("우회전");
            delay(5);
          }
          else {
            stopMove();
          }
        }
        break;
      case 'l': //좌회전
        while (BTSerial.read() != 'L') {
          if (UltrasonicSensor() >= 10.00) {
            leftMove();
            Serial.println("좌회전");
            delay(5);
          }
          else{
            stopMove();
          }
        }
        break;
    }
  }
  nowBT = 'c';
  delay(100);
}

// 자동 move
void AutoMove() {

  // 적외선 센서
  int val1 = digitalRead(irPin[3]);  // 적외선 왼쪽
  int val2 = digitalRead(irPin[2]);  // 적외선 중앙 왼쪽
  int val3 = digitalRead(irPin[1]);  // 적외선 중앙 오른쪽
  int val4 = digitalRead(irPin[0]);  // 적외선 오른쪽

  Serial.print("맨 왼쪽 : ");
  Serial.print(val1);
  Serial.print("\t");
  Serial.print("중앙 왼쪽 : ");
  Serial.print(val2);
  Serial.print("중앙 오른쪽 : ");
  Serial.print(val3);
  Serial.print("\t");
  Serial.print("맨 오른쪽 : ");
  Serial.println(val4);

  //전진
  if (val2 == 1 && val3 == 1) {
    straightMove();
  }
  else if (val1 == 0 && val2 == 0 && val3 == 1 && val4 == 0) {
    weekrightMove();
    weekleftMove();
    nowState = 'L';
  }
  else if (val1 == 0 && val2 == 1 && val3 == 0 && val4 == 0) {
    weekleftMove();
    nowState = 'R';
  }
  else if (val1 == 0 && val2 == 0 && val3 == 1 && val4 == 1) {
    rightMove();
    nowState = 'L';
  }
  else if (val1 == 1 && val2 == 1 && val3 == 0 && val4 == 0) {
    leftMove();
    nowState = 'R';
  }
  else if (val1 == 1 && val2 == 0 && val3 == 0 && val4 == 0) {
    hugeLeftMove();
    nowState = 'R';
  }
  else if (val1 == 0 && val2 == 0 && val3 == 0 && val4 == 1) {
    hugeRightMove();
    nowState = 'L';
  }
  // 정지
  else if (val1 == 0 && val2 == 0 && val3 == 0 && val4 == 0) {
    if (nowState == 'R')
    {
      leftMove();
    }
    else if (nowState == 'L') {
      rightMove();
    }
  }
}
//---------------------------------------------------------------------------------------------------------------------
void leftMove() {
  digitalWrite(motorPin[0], LOW);
  digitalWrite(motorPin[1], HIGH);
  digitalWrite(motorPin[2], LOW);
  digitalWrite(motorPin[3], HIGH);
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[1], i * 1.2);
    analogWrite(speedPin[0], i * 0.95);
  }
  delay(5);
  pSpeed = Speed;
}

void rightMove() {
  digitalWrite(motorPin[0], HIGH);
  digitalWrite(motorPin[1], LOW);
  digitalWrite(motorPin[2], HIGH);
  digitalWrite(motorPin[3], LOW);
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[1], i * 0.95);
    analogWrite(speedPin[0], i * 1.2);
  }
  delay(5);
  pSpeed = Speed;
}

void weekleftMove() {
  digitalWrite(motorPin[0], LOW);
  digitalWrite(motorPin[1], HIGH);
  digitalWrite(motorPin[2], HIGH);
  digitalWrite(motorPin[3], LOW);
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[1], i * 0.6);
    analogWrite(speedPin[0], i * 1);
  }
  delay(5);
  pSpeed = Speed;
}

void weekrightMove() {
  digitalWrite(motorPin[0], LOW);
  digitalWrite(motorPin[1], HIGH);
  digitalWrite(motorPin[2], HIGH);
  digitalWrite(motorPin[3], LOW);
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[1], i * 1);
    analogWrite(speedPin[0], i * 1);
  }
  delay(5);
  pSpeed = Speed;
}

void hugeLeftMove() {
  digitalWrite(motorPin[0], LOW);
  digitalWrite(motorPin[1], HIGH);
  digitalWrite(motorPin[2], LOW);
  digitalWrite(motorPin[3], HIGH);
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[1], i);
    analogWrite(speedPin[0], i * 1.3);
  }
  delay(5);
  pSpeed = Speed;
}

void hugeRightMove() {
  digitalWrite(motorPin[0], HIGH);
  digitalWrite(motorPin[1], LOW);
  digitalWrite(motorPin[2], HIGH);
  digitalWrite(motorPin[3], LOW);
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[1], i * 1.3);
    analogWrite(speedPin[0], i);
  }
  delay(5);
  pSpeed = Speed;
}

void stopMove() {
  for (int i = Speed; i >= 0; i = i - 5) {
    analogWrite(speedPin[1], i);
    analogWrite(speedPin[0], i);
  }
}

void straightMove() {
  digitalWrite(motorPin[0], LOW);
  digitalWrite(motorPin[1], HIGH);
  digitalWrite(motorPin[2], HIGH);
  digitalWrite(motorPin[3], LOW);
  //  analogWrite(speedPin[1], 140);
  //  analogWrite(speedPin[0], 140);
  // 점차 증가하게 함.
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[0], i);
    analogWrite(speedPin[1], i);
  }
  delay(5);
  pSpeed = Speed;
}

void backMove() {
  digitalWrite(motorPin[0], HIGH);
  digitalWrite(motorPin[1], LOW);
  digitalWrite(motorPin[2], LOW);
  digitalWrite(motorPin[3], HIGH);
  // 점차 증가하게 함.
  for (int i = pSpeed; i <= Speed; i = i + 5) {
    analogWrite(speedPin[0], i);
    analogWrite(speedPin[1], i);
  }
  delay(5);
  pSpeed = Speed;
}

// 초음파센서---------------------------------------------------------------------------------------------------------------------
//float UltrasonicSensor() {
//  digitalWrite(trigPin, HIGH);
//  delay(10);
//  digitalWrite(trigPin, LOW);
//  float duration = pulseIn(echoPin, HIGH); // echoPin이 HIGH로 유지되는 시간을 마이크로초로 반환. 즉, 초음파를 보냈다가 다시 들어오는 시간을 반환(왕복시간 us(마이크로초)단위로 반환)
//  //물체와의 거리 계산 거 = 속 * 시  cm 단위로 계산 초음파 속력 : 340m/s
//  float distance = ((float)(340 * duration) / 10000) / 2;
//  Serial.print(duration);
//  Serial.print("us");
//  Serial.print(",");
//  // Serial.print(" distance : ");
//  Serial.print(distance);
//  Serial.println("cm");
//  return distance;
//}
//---------------------------------------------------------------------------------------------------------------------

//
//  전진
//  digitalWrite(motorPin[0], LOW);
//  digitalWrite(motorPin[1], HIGH);
//  digitalWrite(motorPin[2], HIGH);
//  digitalWrite(motorPin[3], LOW);

// 왼쪽 바퀴 전진
//  digitalWrite(motorPin[2], HIGH);
//  digitalWrite(motorPin[3], LOW);
// 오른쪽 바퀴 전진
//  digitalWrite(motorPin[0], LOW);
//  digitalWrite(motorPin[1], HIGH);
// 왼쪽 바퀴 후진
//  digitalWrite(motorPin[2], LOW);
//  digitalWrite(motorPin[3], HIGH);
// 오른쪽 바퀴 후진
//  digitalWrite(motorPin[0], HIGH);
//  digitalWrite(motorPin[1], LOW);

//  // DC 모터 구동---------------------------------------------------------------------------------------------------------------------
//  //전진
//  if (val2 == 1 && val3 == 1) {
//    straightMove();
//  }
//  // WEEK좌회전
//  else if (val1 == 0 && val2 == 0 && val3 == 1 && val4 == 0) {
//    weekleftMove();
//    nowState = 'L';
//  }
//  // WEEK우회전
//  else if (val1 == 0 && val2 == 1 && val3 == 0 && val4 == 0) {
//    weekrightMove();
//    nowState = 'R';
//  }
//  // 좌회전
//  else if (val1 == 0 && val2 == 0 && val3 == 1 && val4 == 1) {
//    leftMove();
//    nowState = 'L';
//  }
//  // 우회전
//  else if (val1 == 1 && val2 == 1 && val3 == 0 && val4 == 0) {
//    rightMove();
//    nowState = 'R';
//  }
//  // 크게 우회전
//  else if (val1 == 1 && val2 == 0 && val3 == 0 && val4 == 0) {
//    hugeRightMove();
//    nowState = 'R';
//  }
//  // 크게 좌회전
//  else if (val1 == 0 && val2 == 0 && val3 == 0 && val4 == 1) {
//    hugeLeftMove();
//    nowState = 'L';
//  }
//  // 정지
//  else if (val1 == 0 && val2 == 0 && val3 == 0 && val4 == 0) {
//    if (nowState == 'L')
//    {
//      leftMove();
//    }
//    else if (nowState == 'R') {
//      rightMove();
//    }
//  }
//---------------------------------------------------------------------------------------------------------------------
