/*Strandtest example code modified Jan 2021 Doug Whitton
 * This example is 
 * 
 * Modified by Amelia Tziougras February 2021
 */


#include <Adafruit_NeoPixel.h>

//Which pin on the Arduino is connected to the NeoPixel
#define LED_PIN 6
//Number of NeoPixels attached
#define LED_COUNT 3

//declare our neopixel strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(50);

}

void loop() {

  int sensorReading = analogRead(A0); //gets the value of the photoresistor and assigns it to the variable


  //runs the colorWipe function on the neopixels if the sensor detects the light is below 70
  if(sensorReading < 70){
  colorWipe(strip.Color(random(255), random(255), random(255)), 150);
  }

  delay(100);
}

void colorWipe(uint32_t color, int wait){
  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, color);
    strip.show();
    delay(wait);
    strip.clear();
  }
}
