/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jamesblack/Documents/IoT/smartshop/SmartShopSourceCode001/src/SmartShopSourceCode001.ino"
/*
 * Project SmartShopSourceCode001
 * Description:SourceCodeforSmartShopController
 * Author:JBlack
 * Date:03-09-23
 */

#include <neopixel.h>
#include <color.h>
#include <IoTClassroom_CNM.h>
#include <math.h>
#include <Adafruit_SSD1306.h>

void setup();
void loop();
#line 14 "/Users/jamesblack/Documents/IoT/smartshop/SmartShopSourceCode001/src/SmartShopSourceCode001.ino"
const int PIXELPIN = D3;    // Exact Pin Data goes to
const int PIXELCOUNT = 46;  // Total number of NeoPixels
const int BUTTONPIN = D4;   // Pin Button is on
int pin = 8; // pin Grove Dust sensor is on
bool buttonState = false;
bool previousButtonState = false;
int startPixel = 0;
int endPixel = 46;
// Define variables for Grove Dust Sensor readings
unsigned long duration;
unsigned long starttime;
unsigned long sampletime_ms = 30000; // Sample time is 30 seconds
unsigned long lowpulseoccupancy = 0;
float ratio = 0;
float concentration = 0;

// Define pin for OLED display reset
#define OLED_RESET D0

// Create OLED display object
Adafruit_SSD1306 display(OLED_RESET);

SYSTEM_MODE(SEMI_AUTOMATIC); // not online
Adafruit_NeoPixel pixel(PIXELCOUNT, PIXELPIN, WS2812B); // exact pixel used

void pixelFill(int startPixel, int endPixel, int hexColor);

void setup() {  
  pixel.begin();      
  pixel.show();
  pixel.setBrightness(30); // sets brightness on scale 1-255
  Wire.begin();

  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0); // Set cursor position for text
  display.printf("SMARTSHOP\n");
  display.printf("Smoke detected!\n");
  display.display();
}

void loop() {  // command that begins the "function" loop is called for repeatedly AFTER set up has executed, main code goes here
  previousButtonState = buttonState;
  buttonState = digitalRead(BUTTONPIN);
  
  duration = pulseIn(pin, LOW);
  lowpulseoccupancy += duration; // Increment low pulse occupancy with each reading

  if (buttonState && !previousButtonState) {  // check if button has just been pressed
    if (pixel.getPixelColor(0) == 0) {  // check if pixels are currently off
      pixelFill(0, 46,0x008000);  // selecting what pixels on track will be filled , selecting the color
    } else {
      pixel.clear(); // turn off pixels
      pixel.show();

      if ((millis() - starttime) > sampletime_ms) {
        ratio = lowpulseoccupancy / (sampletime_ms * 10.0); // Calculate ratio
        concentration = 1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) + 520 * ratio + 0.62; // Calculate concentration
        // If concentration is greater than or equal to 3000, display message on OLED screen
        if (concentration >= 3000) {
          display.clearDisplay();
          display.setTextSize(1);
          display.setTextColor(WHITE);
          display.setCursor(0,0);
          display.printf("SMARTSHOP\n");
          display.printf("Smoke detected!\n");
          display.display();
        }

        // Reset variables for next reading
        lowpulseoccupancy = 0;
        starttime = millis();
      }
    }
  }
}

void pixelFill(int startPixel, int endPixel, int hexColor) {
  
}