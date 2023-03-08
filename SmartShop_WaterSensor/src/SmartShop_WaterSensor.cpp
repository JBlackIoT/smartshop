/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jamesblack/Documents/IoT/smartshop/SmartShop_WaterSensor/src/SmartShop_WaterSensor.ino"
/*
 * Project SmartShop_WaterSensor
 * Description: Water sensor 
 * Author: JBlack
 * Date: 02-07-2023
 */



void setup();
void loop();
#line 10 "/Users/jamesblack/Documents/IoT/smartshop/SmartShop_WaterSensor/src/SmartShop_WaterSensor.ino"
const int waterSens = A3; // define water sensor
int val;
SYSTEM_MODE (SEMI_AUTOMATIC);
void setup() {
  pinMode(waterSens, INPUT); // set water sensor as an input
  Serial.begin(9600); // initialize Serial  
}

void loop() {
  val = analogRead(waterSens); // read the water sensor
  Serial.printf("Water level value = %d\n", val); // print the water level value to Serial
  delay(1000);
}
