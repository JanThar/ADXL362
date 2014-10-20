//First rought testsketch for the Spark Buttons shield

//!!!! For using the WS2812-ring on the Spark button the neopixel library
// has to be manually added - the #include statement is not enough. Sorry.

// This #include statement was automatically added by the Spark IDE.
//#include "neopixel/neopixel.h"
#include "ADXL362/ADXL362.h"
#include "application.h"

#define PIXEL_PIN A7
#define PIXEL_COUNT 11
#define PIXEL_TYPE WS2812B

ADXL362 xl;

int temp;
int XValue, YValue, ZValue, Temperature;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
    xl.begin(A2);              
    xl.beginMeasure();             
    
    strip.begin();
    strip.show(); 
}

void loop() {
    xl.readXYZTData(XValue, YValue, ZValue, Temperature);
    for(int i=0; i<strip.numPixels(); i++) {
     strip.setPixelColor(i, (char)(XValue/0xFF), (char)(YValue/0xFF), (char)(ZValue/0xFF));
    }
    strip.show();
    delay(100);     
}