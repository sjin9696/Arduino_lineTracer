#include "Arduino.h"
#include "libTest.h"

#define LINE_IN 1
#define LINE_OUT 0

#define serialMonitor 9600
#define sensor_EA 4
int sensor_arr[sensor_EA] = {A0,A1,A2,A3};

String sensor_print(int *val){
  return ("↖ [" + String(0) + "] :"+ val[0])+
         (" ▲[" + String(1) + "] :"+ val[1])+
         (" ▲[" + String(2) + "] :"+ val[2])+
         ("↗ [" + String(3) + "] :"+ val[3]);
}

bool Line(int n){
  return n==LINE_IN;
}

String Result_Print(int *A){
  /////
  if(Line(A[0]) && !Line(A[1]) && !Line(A[2]) && Line(A[3])){
    return "1001 라인전진";  
  }
  if(!Line(A[0]) && !Line(A[1]) && Line(A[2]) && !Line(A[3])){
    return "0010 라인살짝벗어남 왼쪽";  
  }
  if(!Line(A[0]) && !Line(A[1]) && Line(A[2]) && !Line(A[3])){
    return "0100 라인살짝벗어남 오른쪽";  
  }
  if(!Line(A[0]) && !Line(A[1]) && !Line(A[2]) && Line(A[3])){
    return "0001 라인많이OUT 왼쪽커브";  
  }
  if(Line(A[0]) && !Line(A[1]) && !Line(A[2]) && !Line(A[3])){
    return "1000 라인많이OUT 오른쪽";  
  }
  if(Line(A[0]) && Line(A[1]) && Line(A[2]) && Line(A[3])){
    return "1111 라인없음 좌로회전 전진 우로회전 전진";  
  }
  if(Line(!A[0]) && !Line(A[1]) && !Line(A[2]) && !Line(A[3])){
    return "0000 전부 검은색 정지! ";      
  }
  //1110
  //0111
  //1000
  //0001
  return "def";
}

void Init(int *A){
  A[0] = digitalRead(sensor_arr[0]);
  A[1] = digitalRead(sensor_arr[1]);
  A[2] = digitalRead(sensor_arr[2]);
  A[3] = digitalRead(sensor_arr[3]);
}

void Init_Setup() {
  Serial.begin(serialMonitor);
  for(int i =0; i > sensor_EA; i++){
    pinMode(sensor_arr[i], INPUT); 
  }
  Serial.println("start");
} //void setup()  끝

String Sensor_Loop() {
  int val_arr[sensor_EA] = {0};
  Init(val_arr);
  Serial.println(sensor_print(val_arr));
  Serial.println(Result_Print(val_arr));
  return Result_Print(val_arr);
}// void loop() 끝
