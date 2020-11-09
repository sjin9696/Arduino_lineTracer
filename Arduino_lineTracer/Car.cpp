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
  if(result=="10"){       // 우회전
      //Controler(STOP); MP3Play(3); delay(2000);
      Controler(RIGHT);
  }
  else if(result=="01"){  // 좌회전
      //Controler(STOP); MP3Play(3); delay(2000);
      Controler(LEFT);
  }
  else{
     Controler(FRONT);
  }
}
