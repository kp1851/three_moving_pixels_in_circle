//***************************************************************
// Original Sketch Written by Marc Miller. (Updated Jan 2016).
// 
// I made some changes
//***************************************************************


#include "FastLED.h"
FASTLED_USING_NAMESPACE

#define DATA_PIN 2          //change
#define NUM_LEDS 24         //change

CRGB leds[NUM_LEDS];

#define MASTER_BRIGHTNESS 64    	// Master brightness (Range is 0-255)

int16_t positionRed = 0;    	  	// Set initial start position of Red pixel
int16_t positionLime = 0;  	    	// Set initial start position of Green pixel
int16_t positionBlue = 8;   	  	// Set initial start position of Blue pixel

int8_t delta = 1;           		// Using a negative value will move pixels backwards.
uint16_t holdTime = 100;   			// Milliseconds to hold position before advancing


void setup() {
  
  //Serial.begin(115200);
  
  delay(1000);  // Startup delay
  
  FastLED.addLeds<WS2812,DATA_PIN,GRB>(leds, NUM_LEDS);
  FastLED.setBrightness(MASTER_BRIGHTNESS);
}

void loop() {  // START MAIN LOOP

  EVERY_N_MILLISECONDS(holdTime) {

    // Set pixel color
    leds[positionRed] = CRGB::Red;       	//Red
    leds[positionLime] = CRGB::Lime;   		//Green
    leds[positionBlue] = CRGB::Blue;     	//Blue
  
    // Show the pixels
    FastLED.show();
   
    // Set pixels back to Black for the next loop around.
    leds[positionRed] = CRGB::Black;
    leds[positionLime] = CRGB::Black;
    leds[positionBlue] = CRGB::Black;
  
    // Set new position, moving (forward or backward) by delta.
    // NUM_LEDS is added to the position before doing the modulo
    // to cover cases where delta is a negative value.
    positionRed = (positionRed + delta + NUM_LEDS) % NUM_LEDS;
    positionLime = (positionLime - delta + NUM_LEDS) % NUM_LEDS;  // - Reverse
    positionBlue = (positionBlue + delta + NUM_LEDS) % NUM_LEDS;

    // Print out position values to see what's happening.
    //Serial.print("pos R = "); Serial.print(positionRed);
    //Serial.print("\t  pos G = "); Serial.print(positionLime);
    //Serial.print("\t  pos B = "); Serial.println(positionBlue);
  }

}
