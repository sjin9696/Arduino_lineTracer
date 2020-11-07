#include "IR_sensor.h"

int sensor_arr[sensor_EA] = {A0,A1,A2,A3};

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

//라인 전진 중에 값이 읽히면.. 작업을 진행. 
void Result_Print(int *A){
 //0<= 검정선 , 1<= 하얀바닥
  Serial.println("\t\t"+String(A[0])+String(A[1])+String(A[2])+String(A[3]));
}
String Sensor_Loop() {
  int val_arr[sensor_EA] = {0};
  Init(val_arr);
  //Result_Print(val_arr);
  return String(!val_arr[0])+String(!val_arr[1]);
}// void loop() 끝
