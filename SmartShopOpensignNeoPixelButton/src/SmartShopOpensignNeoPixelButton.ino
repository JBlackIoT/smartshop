/*
 * Project L04_04_pixelFill
 * Description:
 * Author:
 * Date:
 */
#include <neopixel.h>
#include <color.h>
#include <IoTClassroom_CNM.h>

const int PIXELPIN = D3;    // Exact Pin Data goes to
const int PIXELCOUNT = 46;  // Total number of NeoPixels
const int BUTTONPIN = D4;   // Pin Button is on

bool buttonState = false;
bool previousButtonState = false;


SYSTEM_MODE(SEMI_AUTOMATIC); // not online
Adafruit_NeoPixel pixel(PIXELCOUNT, PIXELPIN, WS2812B); // exact pixel used

void pixelFill(int startPixel, int endPixel, int hexColor); // Command creating a function called pixelFill (integer for where it starts, and where it ends on track, integer for hex color)

void setup() {   // function that does not return a value during "set up" called initialize the variables, pins, libraries the program needs to use
  pinMode(BUTTONPIN,INPUT_PULLDOWN);
  pixel.begin();      
  pixel.show();
  pixel.setBrightness(30); // sets brightness on scale 1-255
}

void loop() {  // command that begins the "function" loop is called for repeatedly AFTER set up has executed, main code goes here
  previousButtonState = buttonState;
  buttonState = digitalRead(BUTTONPIN);

  if (buttonState && !previousButtonState) {  // check if button has just been pressed
    if (pixel.getPixelColor(0) == 0) {  // check if pixels are currently off
      pixelFill(0, 46,0x008000);  // selecting what pixels on track will be filled , selecting the color
    } else {
      pixel.clear(); // turn off pixels
      pixel.show();
    }
  }
}

void pixelFill(int startPixel, int endPixel, int hexColor) {    // command and integer that sets up equation to be calculated by CPU
  for (int i = startPixel; i <= endPixel; i++) {   // the equation is if i = startPixel then i is less than total or end of track including all pixels, the direction is up i guess that's what ++ is? 
    pixel.setPixelColor(i, hexColor);       // command to set the pixel color then (we have established that pixel = i so this is pointing back to above where we said pink)
  }
  pixel.show();      // command to show pixels
  
}