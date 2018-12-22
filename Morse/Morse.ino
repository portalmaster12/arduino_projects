char *letters[]= {".-**","-...","-.-.","-..*",".***","..-.","--.*","....","..**",".---","-.-*",".-..","--**","-***.","---*",".--**.","--.-",".-.*","...*","-***","..-*","...-",".--**","-..-","-.--","--.."};
char ch;
char *ch2;
int count = 0;
char morsechar;

int uppercase_max = 90;
int uppercase_min = 65;
int lowercase_max = 122;
int lowercase_min= 97;
char space = 32;
int space_delay = 2000;
int char_delay = 1000;
int dot_delay = 100;
int off_delay = 300;

void setup() {
 
 Serial.begin(9600);
 Serial.println("hello");
 Serial.println(letters[0][0]);
 pinMode(2, OUTPUT);
 digitalWrite(2, LOW);
 
}

void loop() {
  digitalWrite(2, LOW);
  if (Serial.available() > 0)
    {
      ch = Serial.read();
      
      if(ch == space){
       Serial.println("Space");
       delay(space_delay);
      }
        ch2 = Char_To_Array(ch,lowercase_min,lowercase_max);
      }
        //ch2 = Char_To_Array(ch,lowercase_min,lowercase_max);
        delay(char_delay);
      while(count != 4)
      {
        morsechar = ch2[count];
        FlashMorse(200, 300, morsechar);
        count++;
        }
        count = 0;
        
        
    }
    


void FlashMorse(int dot, int off, char character)
{
  char *dotchar = ".";
  char *dashchar = "-";
  if(character == *dashchar){
   digitalWrite(2, HIGH);
   tone(7, 300, dot*3);
   delay(dot*3);
   digitalWrite(2, LOW);
   delay(off);
  }
  if(character == *dotchar){
   digitalWrite(2, HIGH);
   tone(7, 300, dot);
   delay(dot);
   digitalWrite(2, LOW);
   delay(off);
  }
}
 char* Char_To_Array(char character,int minID,int maxID)
{
 char characternum;
 char *result = " ";
 if(int(character)<=maxID && int(character)>=minID){
 Serial.println("current character");
 Serial.println(character);
 characternum = character-minID;
 result = letters[characternum];
 Serial.println(result);
 return(result);
 }
}




