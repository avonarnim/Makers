#include <Adafruit_NeoPixel.h>
#include <Adafruit_GFX.h>
#include <Adafruit_NeoMatrix.h>

 
#ifndef PSTR
#define PSTR // Make Arduino Due happy
#endif
 
#define PIN 7

Adafruit_NeoMatrix matrix = Adafruit_NeoMatrix(32, 8, PIN,
NEO_MATRIX_BOTTOM + NEO_MATRIX_RIGHT +
NEO_MATRIX_COLUMNS + NEO_MATRIX_ZIGZAG,
NEO_GRB + NEO_KHZ800);

void setup() 
{
  matrix.begin();
  Serial.begin(9600); 
}

//This is in RGB format (0-256)
// Custom colors
uint16_t cardinal = matrix.Color(196, 30, 58);
uint16_t gold = matrix.Color(255, 215, 0);
 
void loop() 
{
    //this is an array representation of the LED screen. 0 will mean that no color is on, while you can choose other colors by accessing the colorMatrix below
    int array1[8][32] = { { 0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,1,0,0,0 }, 
                          { 0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0 }, 
                          { 0,0,1,1,1,0,0,0,1,1,1,0,0,1,1,1,0,0,0,0,0,1,1,1,1,1,1,1,1,0,0,0 }, 
                          { 0,0,1,1,1,0,0,0,1,1,1,0,0,0,1,1,1,1,0,0,0,1,1,1,0,0,0,0,0,0,0,0 }, 
                          { 0,0,1,1,1,0,0,0,1,1,1,0,0,0,0,1,1,1,1,0,0,1,1,1,0,0,0,0,0,0,0,0 }, 
                          { 0,0,0,1,1,1,0,1,1,1,0,0,0,0,0,0,1,1,1,0,0,1,1,1,1,1,1,1,1,0,0,0 }, 
                          { 0,0,0,1,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,0,0,0,1,1,1,1,1,1,1,0,0,0 }, 
                          { 0,0,0,0,1,1,1,1,1,0,0,0,0,1,1,1,1,1,0,0,0,0,0,1,1,1,1,1,1,0,0,0 } };

    //add your colors in this matrix here
    uint16_t colorMatrix[2] = {cardinal, gold};

    /*Write a function that will be able to read all the values in the array and draw them onto the led panel!
     * HINT: Use drawPixel(int x, int y, uint16_t)
     * HINT: Use two nested for loops!
     */
     for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 32; j++) {
        matrix.drawPixel(j, i, colorMatrix[array1[i][j]]);
      }
     }
    
    matrix.setBrightness(20);
    matrix.show();
     
}
