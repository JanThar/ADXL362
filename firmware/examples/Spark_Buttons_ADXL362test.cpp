//First rought testsketch for the Spark Buttons shield
#include "neopixel/neopixel.h"
#include "ADXL362/ADXL362.h"
#include "application.h"

// IMPORTANT: Set pixel COUNT, PIN and TYPE
#define PIXEL_PIN A7
#define PIXEL_COUNT 11
#define PIXEL_TYPE WS2812B

ADXL362 xl;

int temp;
int XValue, YValue, ZValue, Temperature;

Adafruit_NeoPixel strip = Adafruit_NeoPixel(PIXEL_COUNT, PIXEL_PIN, PIXEL_TYPE);

void setup() {
    xl.begin(A2);                   // Setup SPI protocol, issue device soft reset
    xl.beginMeasure();              // Switch ADXL362 to measure mode  
    
    strip.begin();
    strip.show(); // Initialize all pixels to 'off'
}

void loop() {
    xl.readXYZTData(XValue, YValue, ZValue, Temperature);
    for(int i=0; i<strip.numPixels(); i++) {
     strip.setPixelColor(i, (char)(XValue/0xFF), (char)(YValue/0xFF), (char)(ZValue/0xFF));
     //strip.setPixelColor(i, 0xFF, 0xFF, 0xFF);
    }
    strip.show();
    delay(100);     
}