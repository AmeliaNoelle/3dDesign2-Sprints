/*Strandtest example code modified Jan 2021 Doug Whitton
 * 
 * Modified February 2021 Amelia Tziougras
 */


#include <Adafruit_NeoPixel.h>

//Which pin on the Arduino is connected to the NeoPixel
#define LED_PIN 6
//Number of NeoPixels attached
#define LED_COUNT 12

//declare our neopixel strip object
Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);


//create specific colours
uint32_t red = strip.Color(128, 0, 128);
uint32_t blue = strip.Color(255, 165,0);
uint32_t  green = strip.Color(0, 255, 0);
//assign colours to an array
uint32_t colours[3] = {red, blue, green};

void setup() {
  strip.begin();
  strip.show();
  strip.setBrightness(50);
  Serial.begin(9600);
}

void loop() {

  colorWipe(strip.Color(128, 0, 128), 250);

}

//cycle through the array displaying the colours inside
void colorWipe(uint32_t color, int wait){
  for(int i=0; i<strip.numPixels(); i++){
    strip.setPixelColor(i, colours[i]);
    strip.show();
    delay(wait);
    strip.clear();
    Serial.println(colours[i]);
  }
}
