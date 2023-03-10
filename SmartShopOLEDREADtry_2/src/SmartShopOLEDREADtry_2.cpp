/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "/Users/jamesblack/Documents/IoT/smartshop/SmartShopOLEDREADtry_2/src/SmartShopOLEDREADtry_2.ino"
/*
 * Project SmartShopOLEDRead
 * Description: Read to OLED screen
 * Author: JBlack
 * Date: 3-07-2023
 */
#include "Adafruit_SSD1306.h"
#include "math.h" 
// Define pin for sensor
void setup();
void loop();
#line 10 "/Users/jamesblack/Documents/IoT/smartshop/SmartShopOLEDREADtry_2/src/SmartShopOLEDREADtry_2.ino"
int pin = 8;

// Define variables for sensor readings
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

void setup() {
  
  Wire.begin();

  // Initialize OLED display
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0); // Set cursor position for text
  display.printf("SMARTSHOP");
  display.display();

  // Set system mode to semi-automatic
  SYSTEM_MODE(SEMI_AUTOMATIC);
}

void loop() {
  duration = pulseIn(pin, LOW);
  lowpulseoccupancy += duration; // Increment low pulse occupancy with each reading

  if ((millis() - starttime) > sampletime_ms) {
    ratio = lowpulseoccupancy / (sampletime_ms * 10.0); // Calculate ratio
    concentration = 1.1 * pow(ratio, 3) - 3.8 * pow(ratio, 2) + 520 * ratio + 0.62; // Calculate concentration

    // If concentration is greater than or equal to 3000, display message on OLED screen
    if (concentration >= 3000) {
      display.clearDisplay();
      display.setTextSize(1);
      display.setTextColor(WHITE);
      display.setCursor(0,0);
      display.printf("SMARTSHOP");
      display.printf("Smoke detected!");
      display.display();
    }

    // Reset variables for next reading
    lowpulseoccupancy = 0;
    starttime = millis();
  }
}