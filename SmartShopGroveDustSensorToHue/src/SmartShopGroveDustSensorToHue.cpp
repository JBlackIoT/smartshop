/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jamesblack/Documents/IoT/smartshop/SmartShopGroveDustSensorToHue/src/SmartShopGroveDustSensorToHue.ino"
/*
 * Project SmartShopGroveDustSensorToHue
 * Description:smokedetectorlightsHUElights
 * Author:JBlack
 * Date:03-08-23
 */
#include "IoTClassroom_CNM.h"
#include <math.h>

void setup();
void loop();
#line 10 "/Users/jamesblack/Documents/IoT/smartshop/SmartShopGroveDustSensorToHue/src/SmartShopGroveDustSensorToHue.ino"
const int BULB5= 5;
const int BULB4=4;
const int BULB3=3;
const int BULB2=2;
const int BULB1=1;
int color;
const int button=D5;
bool buttonState;
bool toggleState;

int pin = 8;
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000;//sampe 30s ;
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;
SYSTEM_MODE (SEMI_AUTOMATIC);

void setup() {
  Serial.begin(9600);
    pinMode(pin,INPUT);
    starttime = millis();
  waitFor(Serial.isConnected,15000);
  
  WiFi.on();
  WiFi.setCredentials("IoTNetwork");

  WiFi.connect();
  while(WiFi.connecting()) {
    Serial.printf(".");
  }
  delay(1000);
  Serial.printf("\n\n");
  

}


void loop() {
  duration = pulseIn(pin, LOW);
    lowpulseoccupancy = lowpulseoccupancy+duration;

    if ((millis()-starttime) > sampletime_ms){
    concentration >=3000;
    duration = millis();
  //switchON ();
    setHue(BULB5,true,HueRed,255,255);
    setHue(BULB4,true,HueRed,255,255);
    setHue(BULB3,true,HueRed,255,255);
    setHue(BULB2,true,HueRed,255,255);
    setHue(BULB1,true,HueRed,255,255);
} 
  
  else {
  setHue(BULB5,false,HueRed,255,255);
  setHue(BULB4,false,HueRed,255,255);
  setHue(BULB3,false,HueRed,255,255);
  setHue(BULB2,false,HueRed,255,255);
  setHue(BULB1,false,HueRed,255,255);
    
  }    //switchOFF ();
    Serial.printf ("sensorread");
}