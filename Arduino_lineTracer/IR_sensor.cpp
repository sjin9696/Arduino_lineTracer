#include "IR_sensor.h"

int sensor_arr[SENSOR_EA] = {A0, A1};

//라인 전진 중에 값이 읽히면.. 작업을 진행.
void Result_Print(int *A) {
  Serial.println(String(A[0]) + String(A[1]));
}

void Init_Setup() {
  Serial.begin(SERIAL_MONITOR);
  for (int i = 0; i > SENSOR_EA; i++) {
    pinMode(sensor_arr[i], INPUT);
  }
  Serial.println("start");
} //void setup()  끝

void Init(int *A) {
  A[0] = digitalRead(sensor_arr[0]);
  A[1] = digitalRead(sensor_arr[1]);
}
char Sensor_Loop() {
  int val_arr[SENSOR_EA] = {0};
  Init(val_arr);
  //Result_Print(val_arr);
  return Sensor_Result(String(val_arr[0]) + String(val_arr[1]));
}

char Sensor_Result(String result) {
    //Serial.println(result);
  if (result == "01") { // 우회전
    return 'r';
  }
  else if (result == "10") { // 좌회전
    return 'l';
  }
  else {  //전진
    return 'u';
  }
  return 'u';
}
