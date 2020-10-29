#include "Arduino.h"
#include "Car.h"

#define Right_Minus 4
#define Right_Plus  5
#define Left_Minus  6
#define Left_Plus   7

#define sensor_led1 8
#define sensor_led2 9
#define sensor_led3 10
#define sensor_led4 11


#define STOP  000
#define FRONT 111
#define BACK  222
#define RIGHT 333
#define LEFT  444

void CarInit() {
  Serial.begin(9600);
  pinMode(Right_Plus, OUTPUT);
  pinMode(Right_Minus, OUTPUT);
  pinMode(Left_Plus, OUTPUT);
  pinMode(Left_Minus, OUTPUT);

  pinMode(sensor_led1, OUTPUT);
  pinMode(sensor_led2, OUTPUT);
  pinMode(sensor_led3, OUTPUT);
  pinMode(sensor_led4, OUTPUT);
}
void led_setting(int a, int b, int c, int d){
  digitalWrite(sensor_led1, a);
  digitalWrite(sensor_led2, b);
  digitalWrite(sensor_led3, c);
  digitalWrite(sensor_led4, d);
}
void Right_Stop(){
  //Serial.println("Right_Stop");
  digitalWrite(Right_Plus, LOW);
  digitalWrite(Right_Minus, LOW);
}
void Left_Stop(){
  //Serial.println("Left_Stop");
  digitalWrite(Left_Plus, LOW);
  digitalWrite(Left_Minus, LOW);
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
    //Serial.println("Stop");
    Right_Stop();
    Left_Stop();
}
void Front(){
    //Serial.println("Front");
    Right_Front();
    Left_Front();
}
void Back(){
    //Serial.println("Back");
    Right_Back();
    Left_Back();
}
void Left(){
  //Serial.println("left");
  Left_Front();
  Right_Back();
}
void Right(){
  //Serial.println("Right");
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
  //String result = Sensor_Loop();
 // led_setting(0, 0, 0, 0);
 //해결해야될 문제., 라인을 벗어나면 제자리에서 돌아서 라인을 찾도록 하자.  급격한 커브 해결 가능. 
 // 왼쪽 오른쪽 지시 가능.
  if(result=="1001 라인전진"){
        Controler(FRONT);
        led_setting(1, 0, 0, 1);
      }
  else if(result=="1011 라인살짝벗어남 왼쪽"){
      Controler(LEFT);
      led_setting(1, 0, 1, 1);
      
  }
  else if(result=="0011 라인살짝벗어남 왼쪽"){
      Controler(LEFT);
      led_setting(0, 0, 1, 1);
  }
  else if(result=="1100 라인살짝벗어남 오른쪽"){
      Controler(RIGHT);
      led_setting(1, 1, 0, 0);
  }
  else if(result=="1101 라인살짝벗어남 오른쪽"){
      Controler(RIGHT);
      led_setting(1, 1, 0, 1);
  }
  else if(result=="0001 라인많이OUT 왼쪽커브"){
      Controler(LEFT);
      led_setting(0, 0, 0, 1);
  }
  else if(result=="0001 라인많이OUT 왼쪽커브"){
      Controler(LEFT);
      led_setting(0, 1, 1, 1);
  }
  else if(result=="1000 라인많이OUT 오른쪽"){
      Controler(RIGHT);
      led_setting(1, 0, 0, 0);
  }
  else if(result=="1110 라인많이OUT 오른쪽"){
      Controler(RIGHT);
      led_setting(1, 1, 1, 0);
  }
  else if(result=="1111 라인없음 좌로회전 전진 우로회전 전진"){
      led_setting(1, 1, 1, 1);
      Controler(LEFT);
  }
  else if(result=="0000 전부 검은색 정지! "){
      led_setting(0, 0, 0, 0);
      Controler(STOP);
  }
  //delay(100);
  //Controler(FRONT);
  //delay(100);
}
