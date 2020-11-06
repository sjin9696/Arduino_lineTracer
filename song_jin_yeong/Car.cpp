#include "Car.h"

String CarStatus;

void CarInit() {
  Serial.begin(9600);
  pinMode(Right_Plus, OUTPUT);
  pinMode(Right_Minus, OUTPUT);
  pinMode(Left_Plus, OUTPUT);
  pinMode(Left_Minus, OUTPUT);
}
void Left_Stop(){
  //Serial.println("Left_Stop");
  digitalWrite(Left_Plus, LOW);
  digitalWrite(Left_Minus, LOW);
}
void Right_Stop(){
  //Serial.println("Right_Stop");
  digitalWrite(Right_Plus, LOW);
  digitalWrite(Right_Minus, LOW);
}
void Right_Front(){
  //Serial.println("Right_Front");
  digitalWrite(Right_Plus, HIGH);
  digitalWrite(Right_Minus, LOW);
}
void Left_Front(){
  //Serial.println("Left_Front");
  digitalWrite(Left_Plus, HIGH);
  digitalWrite(Left_Minus, LOW);
}
void Right_Back(){
  //Serial.println("Right_Back");
  digitalWrite(Right_Plus, LOW);
  digitalWrite(Right_Minus, HIGH);
}
void Left_Back(){
  //Serial.println("Left_Back");
  digitalWrite(Left_Plus, LOW);
  digitalWrite(Left_Minus, HIGH);
}
void Stop(){
    Right_Stop();
    Left_Stop();
}
void Front(){
    Right_Front();
    Left_Front();
}
void Back(){
    Right_Back();
    Left_Back();
}
void Left(){
  Left_Front();
  Right_Back();
}
void Right(){
  Right_Front();
  Left_Back();
}
void Controler(int n_commend){
  switch(n_commend){
    case FRONT:
      Front();
      break;
    case STOP:
      Stop();
      break;
    case BACK:
      Back();
      break;
    case LEFT:
      Left();
      break;
    case RIGHT:
      Right();
      break;
  }//switch(n_commend) 끝
}//void Controler(int commend) 끝

void Car_loop(String result) {
Serial.println(result);
  //0<= 검정선 , 1<= 하얀바닥
  //1011 왼쪽으로 진행.
  //0111 왼쪽으로진행
  //1001 진행
  //1101 오른쪽으로 진행.
  //1110 오른쪽으로 진행

  //String result = Sensor_Loop();
 //해결해야될 문제., 라인을 벗어나면 제자리에서 돌아서 라인을 찾도록 하자.  급격한 커브 해결 가능. 
 // 왼쪽 오른쪽 지시 가능.
  if(result=="1001"){
        Controler(FRONT);
      }
  else if(result=="1011" || result=="0111" ||result=="0011"||result=="0001"){// 라인살짝벗어남 오른쪽"){
      Controler(RIGHT);
  }
  else if(result=="1101" || result=="1110" ||result=="1100"||result=="1000"){// 라인살짝벗어남 왼쪽"){
      Controler(LEFT);
  }
  else if(result=="1111" || result=="0000"){// 라인없음 좌로회전 전진 우로회전 전진"){
      Controler(FRONT);
  }
  else if(result=="뒤로 BACK"){
      Controler(BACK);
  }
}
