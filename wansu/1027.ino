#include <SoftwareSerial.h>

#include <Arduino_APDS9960.h>

#define BT_RXD 2

#define BT_TXD 1

SoftwareSerial bluetooth(BT_RXD, BT_TXD);

int trigerPin = 0;

int echoPin = 13;
////////////////////////////////////////////////센서핀
int LLLsensor = 11;  int LLLval = 0;

int LLsensor = 17;  int LLval = 0;

int Rsensor = 15;  int Rval = 0;

int Lsensor = 16; int Lval = 0;

int RRsensor = 14;   int RRval = 0;

int RRRsensor = 12;   int RRRval = 0;
////////////////////////////////////////////////모터핀
int RPWM = 10; int Rwheel_1 = 9; int Rwheel_2 = 8;

int LPWM = 5; int Lwheel_1 = 7; int Lwheel_2 = 6;
////////////////////////////////////////////////
int weight = 0; // 가중치

int speed = 120;

char nowState = ' ';

char nowBT = ' ';

char lastBT = ' ';

void setup() {
  Serial.begin(9600);
  bluetooth.begin(9600);

  //적외선센서핀 RRR이 가장바깥쪽 Right
  pinMode(Rsensor, INPUT);
  pinMode(Lsensor, INPUT);
  pinMode(LLsensor, INPUT);
  pinMode(RRsensor, INPUT);
  pinMode(LLLsensor, INPUT);
  pinMode(RRRsensor, INPUT);
  //모터드라이브 핀
  pinMode(RPWM, OUTPUT);
  pinMode(LPWM, OUTPUT);
  pinMode(Rwheel_1, OUTPUT);
  pinMode(Rwheel_2, OUTPUT);
  pinMode(Lwheel_1, OUTPUT);
  pinMode(Lwheel_2, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  //적외선센서값 받기
  Rval = digitalRead(Rsensor);
  Lval = digitalRead(Lsensor);
  RRval = digitalRead(RRsensor);
  LLval = digitalRead(LLsensor);
  RRRval = digitalRead(RRRsensor);
  LLLval = digitalRead(LLLsensor);

  SerialMonitor();
  //RGB센서값 받기

  Auto();

  //blueTooth값 받기.
  if (bluetooth.available())
  {
    nowBT = bluetooth.read();//현재값을 nowBT에 저장
    Serial.print("뭐가왔는가");
    Serial.println(nowBT);
    if (nowBT == 'a' || nowBT == 'c')
    { //수동,자동일경우만 lastBT에 저장.
      lastBT = nowBT;
    }

  }
  //수동모드,자동모드 설정
  //버튼을 누르는상태이면 touchDown으로 소문자
  //버튼을 때는순간 touchUp으로 대문자
  if (lastBT == 'a')
  { //자동이면
    Auto();
    Serial.println("자동");
  }
  else if (lastBT == 'c')
  {
    LWheel(20);
    RWheel(20);
    switch (nowBT)
    {
      case 'u'://전진
        while (bluetooth.read() != 'U') //버튼을떼기 전까지
        {
          LWheel(100);
          RWheel(100);
          Serial.println("전진");
          delay(50);
        }
        break;
      case 'd'://후진
        while (bluetooth.read() != 'D') //버튼을떼기 전까지
        {
          MLWheel(20);
          MRWheel(20);
          Serial.println("후진");
          delay(50);
        }
        break;
      case 'l'://좌회전
        while (bluetooth.read() != 'L') //버튼을떼기 전까지
        {
          LWheel(20);
          RWheel(120);
          Serial.println("좌회전");
          delay(50);
        }
        break;
      case 'r'://우회전
        while (bluetooth.read() != 'R') //버튼을떼기 전까지
        {
          LWheel(140);
          RWheel(20);
          Serial.println("우회전");
          delay(50);
        }
        break;
    }
    nowBT = 'c';
  }
  delay(100);
}
void LWheel(int weight)
{

  digitalWrite(Lwheel_1 , HIGH);
  digitalWrite(Lwheel_2 , LOW);
  analogWrite(LPWM, speed + weight);
  Serial.print("LWheel = ");
  Serial.println((String)weight);
}
void RWheel(int weight)
{
  digitalWrite(Rwheel_1 , HIGH);
  digitalWrite(Rwheel_2 , LOW);
  analogWrite(RPWM, speed + weight);
  Serial.print("RWheel = ");
  Serial.println((String)weight);
}
void MLWheel(int weight)
{

  digitalWrite(Lwheel_1 , LOW);
  digitalWrite(Lwheel_2 , HIGH);
  analogWrite(LPWM, speed + weight);
  Serial.print("MLWheel = ");
  Serial.println((String)weight);
}
void MRWheel(int weight)
{
  digitalWrite(Rwheel_1 , LOW);
  digitalWrite(Rwheel_2 , HIGH);
  analogWrite(RPWM, speed + weight);
  Serial.print("MRWheel = ");
  Serial.println((String)weight);
}
void SerialMonitor()
{
  Serial.print("LLLval = " + (String)LLLval);
  Serial.print("  LLval = " + (String)LLval);
  Serial.print("  Lval = " + (String)Lval);
  Serial.print("  Rval = " + (String)Rval);
  Serial.print("  RRval = " + (String)RRval);
  Serial.print("  RRRval = " + (String)RRRval);
  Serial.println("");
}
void Auto()//Auto
{
  if ((Rval == 1 && Lval == 1 ) || (RRval == 0 && LLval == 0 ))
  {
    LWheel(0);
    RWheel(0);
  }
  else if ((Rval == 1 && Lval == 0 ) || (RRval == 0 && LLval == 0 ))
  {
    LWheel(40);
    RWheel(0);
  }
  else if ((Rval == 0 && Lval == 1 ) || (RRval == 0 && LLval == 0 ))
  {
    LWheel(00);
    RWheel(40);
  }
  else if (Rval == 0 && RRval == 0 && ((Lval || LLval) == 1))
  {
    MLWheel(-20);
    RWheel(35);
    nowState = 'R';
  }
  else if (Rval == 1 && RRval == 0 && ((Lval || LLval) == 1))
  {
    MLWheel(-20);
    RWheel(25);
    nowState = 'R';
  }
  else if (Rval == 0 && RRval == 0 && Lval == 0 && LLval == 0)
  {
    if (nowState == 'R')
    {
      MLWheel(-22);
      RWheel(45);
    }
    else if (nowState == 'L')
    {
      LWheel(45);
      MRWheel(-20);
    }
  }
  else if (Lval == 0 && LLval == 0 && ((Rval || RRval) == 1))
  {
    MRWheel(-20);
    LWheel(35);
    nowState = 'L';
  }
  else if (Lval == 1 && LLval == 0 && ((Rval || RRval) == 1))
  {
    MRWheel(-20);
    LWheel(25);
    nowState = 'L';
  }
}
int UltraSound()
{
  digitalWrite(trigerPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigerPin, LOW);
  int distance = pulseIn(echoPin, HIGH) / 58;
  Serial.println("distance = " + String(distance));
  return distance;
}
