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

uint16_t color = matrix.Color(124,12,24);

void setup() 
{
  matrix.begin();
  matrix.setBrightness(20);
  
  Serial.begin(9600); 
}

//you can keep these colors or custom make them! In RGB format
uint16_t none = matrix.Color(0, 0, 0);
uint16_t yellow = matrix.Color(255, 215, 0);
uint16_t blue = matrix.Color(0, 0, 145);
uint16_t white = matrix.Color(255, 255, 255);
uint16_t red = matrix.Color(170, 0, 0);

int horizontal_scooch = 0;

void loop() 
{
    //design array!
    int array1[8][23] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 1,1,1,2,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

    int array2[8][23] = { { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 1,1,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 0,1,1,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 0,0,1,1,1,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }, 
                          { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 } };

    int array3[8][9] = { { 0,0,0,0,0,0,0,0,0 },
                         { 0,0,0,2,2,2,0,0,0 },
                         { 0,2,2,2,2,2,2,2,0 },
                         { 0,2,3,3,3,3,2,2,0 },
                         { 0,2,4,3,4,3,2,2,0 },
                         { 0,2,2,2,2,2,2,2,0 },
                         { 0,2,0,2,0,2,0,2,0 },
                         { 0,0,0,0,0,0,0,0,0 } };

    //store all your colors here!
    uint16_t colorMatrix[5] = {none, yellow, red, white, blue};

    /*you can use a nested for loop here to show your array! How would you use translate this 2D array into printing things out onto the LED?
     * ANSWER: use matrix.drawPixel() :)
     * Things to think about:
     * 1. adding delays could create cool effects
     * 2. Do you want to do Matrix.Show() after each pixel is drawn for a dynamic effect? (The answer is yes)
     */
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 23; j++) {
        int horizontal_val = (j+horizontal_scooch)%23;
        if (horizontal_scooch%2 == 0) {
          matrix.drawPixel(horizontal_val, i, colorMatrix[array1[i][j]]);
        } else {
          matrix.drawPixel(horizontal_val, i, colorMatrix[array2[i][j]]);
        }
      }
    }
    for (int i = 0; i < 8; i++) {
      for (int j = 0; j < 9; j++) {
        matrix.drawPixel(j+23, i, colorMatrix[array3[i][j]]);
      }
    }

    if (horizontal_scooch > 15) {
      horizontal_scooch = 0;
    } else {
      horizontal_scooch += 1;
    }

    delay(200);
    matrix.show();
     
}
