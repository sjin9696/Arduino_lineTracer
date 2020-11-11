#include "IR_sensor.h"
#include "Car.h"
int sensor_arr[SENSOR_EA] = {A0, A1, A2};

void Init_Setup() {
  Serial.begin(SERIAL_MONITOR);
  pinMode(sensor_arr[0], INPUT);
  pinMode(sensor_arr[1], INPUT);
  pinMode(sensor_arr[2], INPUT);
} //void setup()  끝

char Sensor_Loop() {
  return Sensor_Result();
}

char Sensor_Result() {
  int A[SENSOR_EA] = {0};
  A[0] = digitalRead(sensor_arr[0]);
  A[1] = digitalRead(sensor_arr[1]);
  A[2] = digitalRead(sensor_arr[2]);
  //Front();
  //정지 
  //주행 
    if ((A[0] == false && A[1] == false && A[2]==true)||
        (A[0] == true && A[1] == true && A[2]==true)||
        (A[0] == true && A[1] == true && A[2]==true)){ //전진
      return 'u';
    }
  if ((A[0] == false && A[1] == true && A[2]==false)||
      (A[0] == false && A[1] == true && A[2]==true)) { // 101우회전
    return 'r';
  }
  if ((A[0] == true && A[1] == false && A[2]==false)||
      (A[0] == true && A[1] == false && A[2]==true)) { // 101좌회전
    return 'l';
  }
  //  111, 000,110,011, 101, 011,
  return 'u';
}
