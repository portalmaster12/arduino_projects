//Ethan Bartlett
//Code for Random LED colors with button
 
//@@@@@@@@@@@@@@@@@@@@@
//set variables for pins
//@@@@@@@@@@@@@@@@@@@@@
const int buttonPin = 12; //conects button to pin 12
const int redPin = 11;  // R petal on RGB LED module connected to digital pin 11
const int greenPin = 10;  // G petal on RGB LED module connected to digital pin 9
const int bluePin = 9;  // B petal on RGB LED module connected to digital pin 10
 
 
//@@@@@@@@@@@@@@@@@@@@@
//set variables for COLORS
//@@@@@@@@@@@@@@@@@@@@@
 
int cols[5][3] = {
 {225, 0, 0},
{0, 255, 0},
{0, 0, 255},
{255, 215, 0},
  {255,255,255}
};
//@@@@@@@@@@@@@@@@@@@@@@
  //set button variable
//@@@@@@@@@@@@@@@@@@@@@@
int button = 0;
 
//@@@@@@@@
//How it starts
//@@@@@@@@
/**************************************************************************/     
void setup()
{
         pinMode(redPin, OUTPUT); // sets the redPin to be an output
         pinMode(greenPin, OUTPUT); // sets the greenPin to be an output
         pinMode(bluePin, OUTPUT); // sets the bluePin to be an output
                               pinMode(buttonPin, INPUT); //sets but to output
}
 
//@@@@@
//Functions
//@@@@
 
/***************************************************************************/
//Changes colors
/***************************************************************************/     
void color (unsigned char red, unsigned char green, unsigned char blue)     // the color generating function 
{   
          analogWrite(redPin, red);  
          analogWrite(bluePin, blue);
          analogWrite(greenPin, green);
}
 
/***************************************************************************/
//randomizer
/***************************************************************************/     
int rd()
{
  int number = random(1, 6);
  return number;
}
 
 
/***************************************************************************/
//color switcher
/***************************************************************************/ 
 
//@@@@@
//button switch colors
//@@@@
 
void loop()  // run over and over again 
{   
                              button = digitalRead(buttonPin);
  if (button == HIGH) {
                                             int n=rd();
          // Basic colors:
          color(cols[n][1],cols[n][2],cols[n][3]); // turn the RGB LED red
                 //delay(500); // delay for 1 second
  }  
}
/******************************************************/ 
