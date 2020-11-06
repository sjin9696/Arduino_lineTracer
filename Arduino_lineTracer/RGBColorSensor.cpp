#include "RGBColorSensor.h"

// Global Variables
SparkFun_APDS9960 apds = SparkFun_APDS9960();
uint16_t ambient_light = 0;
uint16_t red_light = 0;
uint16_t green_light = 0;
uint16_t blue_light = 0;
int largest;
int color; //r: 0, g: 1, b:2

void RGBsensor_setup() {
  // Initialize Serial port
  Serial.begin(9600);
  Serial.println();
  Serial.println(F("--------------------------------"));
  Serial.println(F("SparkFun APDS-9960 - ColorSensor"));
  Serial.println(F("--------------------------------"));

  // Initialize APDS-9960 (configure I2C and initial values)
  if ( apds.init() ) {
    Serial.println(F("APDS-9960 initialization complete"));
  } else {
    Serial.println(F("Something went wrong during APDS-9960 init!"));
  }

  // Start running the APDS-9960 light sensor (no interrupts)
  if ( apds.enableLightSensor(false) ) {
    Serial.println(F("Light sensor is now running"));
  } else {
    Serial.println(F("Something went wrong during light sensor init!"));
  }
  
  // Wait for initialization and calibration to finish
  delay(500);
}

String RGBsensor_loop() {
  String res ="";
  largest = 0;
  // Read the light levels (ambient, red, green, blue)
  if (!apds.readAmbientLight(ambient_light)||!apds.readRedLight(red_light) ||
      !apds.readGreenLight(green_light)    ||!apds.readBlueLight(blue_light)){
    Serial.println("Error reading light values");
  } 
  else {
    int v[3] = {red_light, green_light, blue_light};
    int largest = v[0];
    
    for (int i = 1; i < 3; ++i)  {
      largest = max(largest, v[i]);    //큰 값을 다시 largest에 대입
    }
    for (int i = 0; i < 3; ++i)  {
      if (largest == v[i]) { //큰 값의 배열 번호를 찾기.
        color = i;
      }
    }
    Serial.print(" Color: ");
    Serial.print(color);
    if (color == 0) {
      res = "red";
      Serial.print(" red ");
    } else if (color == 1) {
      res = "Green";
      Serial.print(" Green ");
    } else if (color == 2) {
      Serial.print(" Blue ");
      res = "Blue";
    }
    Serial.print(" MAX: ");
    Serial.print(largest);
  }
  return res;
  // Wait 1 second before next reading
 // delay(1000);
}
