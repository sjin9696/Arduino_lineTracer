#include "choumpa.h"
#include "arduino.h"

int trigPin = 15;                  // 초음파 센서
int echoPin = 14;                  // 초음파 센서

void Ultrasonicsetup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
}

float UltrasonicSensor() {
  digitalWrite(trigPin, HIGH);
  delay(10);
  digitalWrite(trigPin, LOW);
  float duration = pulseIn(echoPin, HIGH); // echoPin이 HIGH로 유지되는 시간을 마이크로초로 반환. 즉, 초음파를 보냈다가 다시 들어오는 시간을 반환(왕복시간 us(마이크로초)단위로 반환)
  //물체와의 거리 계산 거 = 속 * 시  cm 단위로 계산 초음파 속력 : 340m/s
  float distance = ((float)(340 * duration) / 10000) / 2;
  Serial.print(duration);
  Serial.print("us");
  Serial.print(",");
  // Serial.print(" distance : ");
  Serial.print(distance);
  Serial.println("cm");
  return distance;
}
