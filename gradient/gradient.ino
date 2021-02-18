/*Strandtest example code modified Jan 2021 Doug Whitton
 * This example is 
 */


#include <Adafruit_NeoPixel.h>

//Which pin on the Arduino is connected to the NeoPixel
#define LED_PIN 6
//Number of NeoPixels attached
#define LED_COUNT 12

int blue = 255;

//declare our neopixel strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(50);

}

void loop() {


  colorWipe(strip.Color(0, 255, blue), 100);

  if(blue == 0){
    blue = 255;
  }else{
  blue = blue - 75;
  }

  


}

void colorWipe(uint32_t color, int wait){
  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
   //strip.clear();
  }
}
