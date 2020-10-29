#include "libTest.h"

#define Right_Plus 4
#define Right_Minus 5
#define Left_Plus 6
#define Left_Minus 7

#define FRONT 111
#define BACK  222
#define RIGHT 333
#define LEFT  444

void setup() {
  Serial.begin(9600);
  pinMode(Right_Plus, OUTPUT);
  pinMode(Right_Minus, OUTPUT);
  pinMode(Left_Plus, OUTPUT);
  pinMode(Left_Minus, OUTPUT);
  Init_Setup();
  
}
void Right_Front(){
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

void Front(){
  Serial.println("Front");
    Right_Front();
    Left_Front();
}
void Back(){
  Serial.println("Back");
    Right_Back();
    Left_Back();
}
void Left(){
  Serial.println("left");
  Left_Front();
  Right_Back();
}
void Right(){
  Serial.println("Right");
  Right_Front();
  Left_Back();
}
void Controler(int n_commend){
  switch(n_commend){
    case FRONT:
      Front();
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

void loop() {
  String result = Sensor_Loop();
  if(result=="1001 라인전진"){
      Controler(FRONT);
  }
  else if(result=="0010 라인살짝벗어남 왼쪽"){
      Controler(LEFT);
  }
   else if(result=="0001 라인많이OUT 왼쪽커브"){
      Controler(LEFT);
  }
   else if(result=="0100 라인살짝벗어남 오른쪽"){
      Controler(RIGHT);
  }
   else if(result=="1000 라인많이OUT 오른쪽"){
      Controler(RIGHT);
  }
  else if(result=="1111 라인없음 좌로회전 전진 우로회전 전진"){
      Controler(FRONT);
      delay(1000);
      Controler(LEFT);
      delay(1000);
      Controler(RIGHT);
      delay(1000);
      Controler(BACK);
      delay(1000);
  }
  delay(500);
}
