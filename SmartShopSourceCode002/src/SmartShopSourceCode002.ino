/*
 * Project SmartShopSourceCode002
 * Description:
 * Author:
 * Date:
 */
#include "IoTClassroom_CNM.h"
#include <math.h>
const int photodiodePin = A1; // reading from photodiode
const int servoPin = D8; //servo pin
int photodiodeValue, brightness;  //int for photodiodevalue , int for brightness
const float OFFSET = 90; 
const float AMP = 90;
float t; // variable for time
float signal; // variable that will be outputted
float freq = 0.2; // frequency for sin-wave. freq = 1/period
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
const int waterSens = A3; // define water sensor
int val;
int relay = 17;

Servo myservo; // create servo object to control a servo
SYSTEM_MODE (SEMI_AUTOMATIC);
void setup()
{
  {
  pinMode(waterSens, INPUT); // set water sensor as an input
  Serial.begin(9600); // initialize Serial  
}
pinMode(relay, OUTPUT);      // Initialize pin as an output

  Serial.begin (9600);
  pinMode(photodiodePin, INPUT);
  myservo.attach(servoPin); // attached to pin D6
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
     photodiodeValue = analogRead(photodiodePin);
  brightness = 255 - (photodiodeValue / 16);
  Serial.printf("\n\n\nphotodiodeValue=%i\n,brightness=%i\n\n\n",photodiodeValue,brightness);
  
 // analogWrite(servoPin, brightness);

// myservo.write(60);
// delay(1000);
// myservo.write(120);
// delay(1100);

  if (photodiodeValue < 600) { // check if it is dark
    signal = AMP * sin(2 * M_PI * freq * t) + OFFSET; //sine wave
    myservo.write(signal); //send via my servo
    t = millis() / 1000.0; //time in milliseconds
  }
  val = analogRead(waterSens);
  if (val > 150){// read the water sensor
  Serial.printf("Water level value = %d\n", val); // print the water level value to Serial
digitalWrite(relay, HIGH);   // Turn the relay on (HIGH is the voltage level = 1)
delay(5000);                 // Stay ON for 5 seconds
digitalWrite(relay, LOW);    // Turn the relay off by making the voltage LOW = 0
delay(3000);                 // Stay OFF for 30 seconds
}
  }