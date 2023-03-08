/*
 * Project SmartShopWaterPumpDLPlug
 * Description: send to plug so pump turns on
 * Author:JBlack
 * Date:03-07-2023
 */


int relay = 17;              // Tells Argon the relay is connected to pin 13
SYSTEM_MODE (SEMI_AUTOMATIC);
void setup()
{
pinMode(relay, OUTPUT);      // Initialize pin as an output
}

void loop()                  
{
digitalWrite(relay, HIGH);   // Turn the relay on (HIGH is the voltage level = 1)
delay(5000);                 // Stay ON for 5 seconds
digitalWrite(relay, LOW);    // Turn the relay off by making the voltage LOW = 0
delay(5000);                 // Stay OFF for 5 seconds
}
