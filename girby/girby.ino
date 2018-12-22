
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//ethan
//girby version 1 code
//uses neo pixel libary:
//https://github.com/adafruit/Adafruit_NeoPixel
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


//***********************************************************

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//A seting up program
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//part A step 1 setting up neo pixel
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

#include <Adafruit_NeoPixel.h> //including neo pixel libary
#define PIN            7 //saying which pin neo pixel is
#define NUMPIXELS      8 //telling it how many lights there are
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800); //defines pixels

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//part A step 2 setting up the varribales
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//sets up the pins for the buttons
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
const int greenB = 2;
const int redB = 3;
const int blueB = 4;
const int yellowB = 5;
const int modeB = 6;
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%


//uses an array to set varribales for colors and sets up randomizer
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
int cols[4][3] = {
 {0, 15, 0}, //green
 {15, 0, 0}, //red
 {0, 0, 15}, //blue
 {7, 7, 0} //yellow
};


int rd()
{
  int number = rand() % 4;
  return number;
}

int button =0;

int counter = 0;

int rans[8] = {1,rd(),rd(),rd(),rd(),rd(),rd(),rd()};

void makelights() {
  
for(int i=0;i<8;i++){

    rans[i] = rd();
    
    // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255 
    //makes random colors then lights up corasponding light
    //pixels.setPixelColor(i, pixels.Color(cols[rans[i]][1],cols[rans[i]][2],cols[rans[i]][3]));
    pixels.setPixelColor(i, pixels.Color(cols[rans[i]][0],cols[rans[i]][1],cols[rans[i]][2]));
    
    pixels.show(); // This sends the updated pixel color to the hardware.
    //delay(750);
    
   }
}
  
 //%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//part A step 3 setting up program
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

void setup() {

pixels.begin();//begins neo pixel

 //says all buttons are inputs
 pinMode(greenB, INPUT);
 pinMode(redB, INPUT);
 pinMode(blueB, INPUT);
 pinMode(yellowB, INPUT);
 pinMode(modeB, INPUT);

 makelights();
}



//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%
//part B running the code
//%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%

//button 'debounce' code: https://www.arduino.cc/en/Tutorial/Debounce

void loop() {

  int x=rans[counter];//matches pin number of button and color as varible

    button = digitalRead(x+2);
  
   if (button == HIGH) {
    pixels.setPixelColor(counter, pixels.Color(0,0,0));
    pixels.show();
    counter++;
  }

}
