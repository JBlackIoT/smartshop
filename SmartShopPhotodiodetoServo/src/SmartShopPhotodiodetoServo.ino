/*
 * Project SmartShopPhotodiodetoServo
 * Description: photo diode contolls servo motor
 * Author: JBlack
 * Date: 02-07-2023
 */

#include <math.h>
const int photodiodePin = A1; // reading from photodiode
const int servoPin = D6; //servo pin
int photodiodeValue, brightness;  //int for photodiodevalue , int for brightness
const float OFFSET = 90; 
const float AMP = 90;
float t; // variable for time
float signal; // variable that will be outputted
float freq = 0.2; // frequency for sin-wave. freq = 1/period

Servo myservo; // create servo object to control a servo
SYSTEM_MODE (SEMI_AUTOMATIC);
void setup() {
  Serial.begin (9600);
  pinMode(photodiodePin, INPUT_PULLUP);
  myservo.attach(servoPin); // attached to pin D6
  
}

void loop() {
  photodiodeValue = analogRead(photodiodePin);
  brightness = 255 - (photodiodeValue / 16);
  Serial.printf("photodiodeValue=%i\n,brightness=%i\n",photodiodeValue,brightness);
  
  analogWrite(servoPin, brightness);

  if (photodiodeValue < 4000) { // check if it is dark
    signal = AMP * sin(2 * M_PI * freq * t) + OFFSET; //sine wave
    myservo.write(signal); //send via my servo
    t = millis() / 1000.0; //time in milliseconds
  }
}

