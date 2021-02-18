/*Strandtest example code modified Jan 2021 Doug Whitton
 * 
 * Modified February 2021 Amelia Tziougras
 */


#include <Adafruit_NeoPixel.h>

//Which pin on the Arduino is connected to the NeoPixel
#define LED_PIN 6
//Number of NeoPixels attached
#define LED_COUNT 12

int opacity = 255;

//declare our neopixel strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(50);

}

void loop() {


  //Fades the brightness of the neopixels over time, then loops
  colorWipe(strip.ColorHSV(180, 100, opacity), 100);

  if(opacity< 75){
    opacity = 255;
  }else{
  opacity = opacity - 75;
  }

  


}

void colorWipe(uint32_t color, int wait){
  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
    strip.clear();
  }
}
