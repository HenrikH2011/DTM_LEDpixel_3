// LEDpixel: SK6812 WWA 3-wire. +VDC / GND / DIN (Data IN)
// Library FastLED.h
// Ref.: https://www.youtube.com/watch?v=4Ut4UK7612M
// DEV: HH 
// IDE: Arduino V2

#include <Arduino.h>
#include <FastLED.h> // library by Daniel Garcia

#define NUM_LEDS 7 // How many LEDpixel to handle
#define LED_PIN 4 // Arduino Pin to connect to LEDpixel DIN Pin
#define Pbutton_1 2 // PushButton on PD2 / INT0 - for external ISR 

CRGB leds[NUM_LEDS]; // array of LEDpixel's (NUM_LEDS)
// RGB_ORDER RGB;

// variable's for turning LEDpixel On or OFF
bool kitchen_status = false;
bool entre_status = false;
bool room_status = false;
bool dinnerRoom_status = false;

bool status_Pbutton_1 = false;
int LED_value = 100; // ledPixel CHSV : V:Value:Brightness

void setup() {
  // put your setup code here, to run once:
  FastLED.addLeds<WS2812B, LED_PIN, GRB>(leds, NUM_LEDS);  // setup the neopixel: type, Pin, leds array, LEDs to hadle
  // SK6812WWA is compatible with WS2812B, keep WS2812B in the library declaration
  // FastLED.setBrightness(50); // set brightness of neopixels

  Serial.begin(9600); // initial serial monitor

/*

 // Test all LED's - Set on
 leds[0] = CHSV (16, 200, 100);
 leds[1] = CHSV (16, 200, 100);
 leds[2] = CHSV (16, 200, 100);
 leds[3] = CHSV (16, 200, 100);
 leds[4] = CHSV (16, 200, 100);
 leds[5] = CHSV (16, 200, 100);
 leds[6] = CHSV (16, 200, 100);

 FastLED.show(); // send data to LEDpixel DIN Pin

 delay(2000);
*/



 leds[0] = CRGB:: White;
 leds[1] = CRGB:: White;
 leds[2] = CRGB:: White;
 leds[3] = CRGB:: White;
 leds[4] = CRGB:: White;
 leds[5] = CRGB:: White;
 leds[6] = CRGB:: White;

 FastLED.show();

 delay(2000);



 leds[0] = CRGB:: Black;
 leds[1] = CRGB:: Black;
 leds[2] = CRGB:: Black;
 leds[3] = CRGB:: Black;
 leds[4] = CRGB:: Black;
 leds[5] = CRGB:: Black;
 leds[6] = CRGB:: Black;

 FastLED.show(); // send data to LEDpixel DIN Pin

 delay(1000);

} // END void setup 

void loop() {

// NOTE: test af SK6812WWA LEDpixel

// Test all LED's - Set on 
 //leds[0] = CHSV (0, 150, 100);
 leds[1] = CHSV (255, 200, LED_value);
 //leds[2] = CHSV (0, 150, 100);
 leds[3] = CHSV (255, 200, LED_value);
 //leds[4] = CHSV (225, 150, 100);
 leds[5] = CHSV (255, 200, LED_value);
 //leds[6] = CHSV (0, 150, 100);

 FastLED.show(); // send data to LEDpixel DIN Pin

 delay(2000);

// Test all LED's - Set on
 //leds[0] = CHSV (0, 150, 100);
 leds[1] = CHSV (220, 200, LED_value);
 //leds[2] = CHSV (0, 150, 100);
 leds[3] = CHSV (220, 200, LED_value);
 //leds[4] = CHSV (225, 150, 100);
 leds[5] = CHSV (220, 200, LED_value);
 //leds[6] = CHSV (0, 150, 100);

 FastLED.show(); // send data to LEDpixel DIN Pin

 delay(2000);

 // Test all LED's - Set on
 //leds[0] = CHSV (0, 150, 100);
 leds[1] = CHSV (200, 200, 100);
 //leds[2] = CHSV (0, 150, 100);
 leds[3] = CHSV (200, 200, 100);
 //leds[4] = CHSV (225, 150, 100);
 leds[5] = CHSV (200, 200, 100);
 //leds[6] = CHSV (0, 150, 100);

 FastLED.show(); // send data to LEDpixel DIN Pin

 delay(2000);



/*

 leds[0] = CRGB (255, 0, 0);
 leds[1] = CRGB (0, 0, 0);
 leds[2] = CRGB (0, 255, 0);
 leds[3] = CRGB (0, 0, 255);
 leds[4] = CRGB (0, 0, 0);
 leds[5] = CRGB (255, 255, 0);
 leds[6] = CRGB (0, 255, 255);

 FastLED.show();


 // delay(2000);
*/
/*
 leds[0] = CRGB:: White;
 leds[1] = CRGB:: White;
 leds[2] = CRGB:: White;
 leds[3] = CRGB:: White;
 leds[4] = CRGB:: White;
 leds[5] = CRGB:: White;
 leds[6] = CRGB:: White;

 FastLED.show();


 delay(2000);

 leds[0] = CRGB:: Black;
 leds[1] = CRGB:: Black;
 leds[2] = CRGB:: Black;
 leds[3] = CRGB:: Black;
 leds[4] = CRGB:: Black;
 leds[5] = CRGB:: Black;
 leds[6] = CRGB:: Black;

 FastLED.show(); // send data to LEDpixel DIN Pin

 delay(1000);
*/

/*

  // set TV ON
  EVERY_N_MILLISECONDS(random(900, 1200)){ // TV random hue, saturation and brightness, change every n millisecond
    leds[3] = CHSV (random8(10, 96), random8(200, 255), random8(50, 100)); // random in the scope (x, y)
    //leds[2] = CHSV (random8(10, 96), random8(200, 255), random8(50, 100)); // random in the scope (x, y)
    leds[2] = CHSV (16, 200, 50); // room light in TV-room
    FastLED.show(); // send data to LEDpixel DIN Pin
  } // END TV ON function
  
 // set dinnerRoom light ON/OFF
  EVERY_N_MILLISECONDS(10000){ 
    if (!dinnerRoom_status){ // if dinnerRoom_status == not true, turn on light
      leds[0] = CHSV (16, 200, 150); // Light ON
      leds[1] = CHSV (16, 200, 150); // Light ON
      FastLED.show();
    } // END if structure
    
    if (dinnerRoom_status){ // if dinnerRoom_status == true, turn light OFF
      leds[0] = CRGB:: Black; // light OFF
      leds[1] = CRGB:: Black; // light OFF
      FastLED.show();
    } // END if structure

    dinnerRoom_status = !dinnerRoom_status; // invert dinnerRoom_status

  } // END dinnerRoom light ON/OFF function


  // set kitchen light ON/OFF
  EVERY_N_MILLISECONDS(4000){ 
    if (!kitchen_status){
      leds[6] = CHSV (16, 200, 150); // Light ON
      FastLED.show();
    } // END if structure
    
    if (kitchen_status){
      leds[6] = CRGB:: Black; // light OFF
      FastLED.show();
    } // END if structure

    kitchen_status = !kitchen_status;

  } // END kitchen light ON/OFF function

  // entre light ON/OFF
  EVERY_N_MILLISECONDS(6000){
    if(!entre_status){
      leds[5] = CHSV (16, 200, 150); // light ON
      FastLED.show();
    } // END if structure

    if (entre_status){
      leds[5] = CRGB:: Black; // light OFF
      FastLED.show();      
    }// END if structure
   
    entre_status = !entre_status;

  }// END entre light ON/OFF

  // room light ON/OFF
  EVERY_N_MILLISECONDS(10000){
    if (!room_status){
      leds[4] = CHSV (16, 200, 150);
      FastLED.show();
    } // END if structure

    if (room_status){
      leds[4] = CRGB::Black;
      FastLED.show();
    } // END if structure

    room_status = !room_status;

  } // END room light ON/OFF function

*/
} // END void loop
