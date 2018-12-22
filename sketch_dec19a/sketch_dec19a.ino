char *letters[]= {".-**","-...","-.-.","-..*",".***","..-.","--.*","....","..**",".---","-.-*",".-..","--**","-***.","---*",".--**.","--.-",".-.*","...*","-***","..-*","...-",".--**","-..-","-.--","--.."};
char ch;
char ch2;
int count = 0;
char morsechar;
char *dot = ".";
char *dash = "-";
void setup() {
 
 Serial.begin(9600);
 Serial.println("hello");
 Serial.println(letters[0][0]);
}

void loop() {
  if (Serial.available() > 0)
    {
      ch = Serial.read();
      
      ch2 = ch-97;
      
      if(ch<123 && ch>96 || ch == 55 || ch == 56){
        Serial.println(ch);
        Serial.println(letters[ch2]);
      while(count != 5)
      {
        morsechar = letters[ch2][count];
        Serial.println(morsechar);
        if(morsechar == *dash){
          Serial.println(500);
        }
        if(morsechar == *dot){
          Serial.println(200);
        }
        
        count++;
       
    }
    Serial.println("Loop Done");
      }
     else{
     Serial.println("Failed");
     }
}
}
