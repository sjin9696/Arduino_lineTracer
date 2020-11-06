#ifndef RGBColorSensor_H
#define RGBColorSensor_H

#include <Wire.h>
#include <SparkFun_APDS9960.h>

void RGBsensor_setup() ;
String RGBsensor_loop();

#endif

/****************************************************************
ColorSensor.ino
APDS-9960 RGB and Gesture Sensor
Shawn Hymel @ SparkFun Electronics
October 15, 2014
https://github.com/sparkfun/APDS-9960_RGB_and_Gesture_Sensor

Tests the color and ambient light sensing abilities of the 
APDS-9960. Configures APDS-9960 over I2C and polls the sensor for
ambient light and color levels, which are displayed over the 
serial console.

Hardware Connections:

IMPORTANT: The APDS-9960 can only accept 3.3V!
 
 Arduino Pin  APDS-9960 Board  Function
 
 3.3V         VCC              Power
 GND          GND              Ground
 A4           SDA              I2C Data
 A5           SCL              I2C Clock

Resources:
Include Wire.h and SparkFun_APDS-9960.h

Development environment specifics:
Written in Arduino 1.0.5
Tested with SparkFun Arduino Pro Mini 3.3V

This code is beerware; if you see me (or any other SparkFun 
employee) at the local, and you've found our code helpful, please
buy us a round!

Distributed as-is; no warranty is given.
****************************************************************/
