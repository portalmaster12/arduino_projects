//7-Segment Display
//You should now see the 7-segment display cycle from 0 to F
//Email:support@sunfounder.com
//Website:www.sunfounder.com
//2015.5.7
const int a=7; //a of 7-segment attach to digital pin 7
const int b=6; //b of 7-segment attach to digital pin 6
const int c=5; //c of 7-segment attach to digital pin 5
const int d=11;//d of 7-segment attach to digital pin 11
const int e=10;//e of 7-segment attach to digital pin 10
const int f=8;//f of 7-segment attach to digital pin 8
const int g=9;//g of 7-segment attach to digital pin 9
const int dp=4;//dp of 7-segment attach to digital pin 4

const int led_1=17;//led
const int led_2=18;
const int led_3=19;
const int led_4=20;
const int led_5=21;

const int mins = 20; //minute pins are in digital pins 24 to 31
const int secs = 0;  //second pins are in digital pins 4 to 11

void setup()
{
  //loop over thisPin from 4 to 11 and set them all to output
  for(int thisPin = 4;thisPin <= 11;thisPin++)
  {
    pinMode(thisPin,OUTPUT);
  }

  for(int minpins = 24; minpins <=31; minpins++)
  {
    pinMode(minpins,OUTPUT);
  }
  
  for(int ledpins = 17; ledpins <=21; ledpins++)
  { 
    pinMode(ledpins,OUTPUT);
  }
  
}

void loop()
{

   for(int minpins = 24; minpins <=31; minpins++)
  {
    digitalWrite(minpins,HIGH);
    digitalWrite(minpins-20,HIGH);
    
   for(int ledpins = 17; ledpins <=21; ledpins++)
   { 
      digitalWrite(ledpins,HIGH);
    }
    
    delay(500);
    digitalWrite(minpins,LOW);
    digitalWrite(minpins-20,LOW);
    
   for(int ledpins = 17; ledpins <=21; ledpins++)
   { 
      digitalWrite(ledpins,LOW);
    }
  }


  digital_0(mins);
  min_1();
  digital_1(mins);
  min_1();
  digital_2(mins);
  min_1();
  digital_3(mins);
  min_1();
  digital_4(mins);
  min_1();
  digital_5(mins);
  min_1();
  digital_6(mins);
  min_1();
  digital_7(mins);
  min_1();
  digital_8(mins);
  min_1();
  digital_9(mins);
  min_1();
  
  
   
}


void min_1()
{



  tensecs();
  digitalWrite(led_1,HIGH);
  tensecs();
  digitalWrite(led_2,HIGH);
  tensecs();
  digitalWrite(led_3,HIGH);
   tensecs();
  digitalWrite(led_4,HIGH);
   tensecs();
  digitalWrite(led_5,HIGH);
  tensecs();

  for(int ledpins = 17; ledpins <=21; ledpins++)
  { 
    digitalWrite(ledpins,LOW);
  }
  
}

void tensecs()
{
  digital_0(secs);
  delay(1000);
  digital_1(secs);//diaplay 1 to the 7-segment
  delay(1000);//wait for a second
  digital_2(secs);//diaplay 2 to the 7-segment
  delay(1000); //wait for a second
  digital_3(secs);//diaplay 3 to the 7-segment
  delay(1000); //wait for a second
  digital_4(secs);//diaplay 4 to the 7-segment
  delay(1000); //wait for a second
  digital_5(secs);//diaplay 5 to the 7-segment
  delay(1000); //wait for a second
  digital_6(secs);//diaplay 6 to the 7-segment
  delay(1000); //wait for a second
  digital_7(secs);//diaplay 7 to the 7-segment
  delay(1000); //wait for a second
  digital_8(secs);//diaplay 8 to the 7-segment
  delay(1000); //wait for a second
  digital_9(secs);
  delay(1000);
}


void digital_1(int w) //diaplay 1 to the 7-segment
{
  digitalWrite(c+w,HIGH);//turn the c of the 7-segment on
  digitalWrite(b+w,HIGH);//turn the b of the 7-segment on
  for(int j = 7;j <= 11;j++)//turn off the others
  {
    digitalWrite(j+w,LOW);
  }
  digitalWrite(dp,LOW);//turn the dp of the 7-segment off
}
void digital_2(int w) //diaplay 2 to the 7-segment
{
  digitalWrite(w+b,HIGH);
  digitalWrite(w+a,HIGH);
  for(int j = 9;j <= 11;j++)
  digitalWrite(w+j,HIGH);
  digitalWrite(w+dp,LOW);
  digitalWrite(c+w,LOW);
  digitalWrite(f+w,LOW);
}
void digital_3(int w) //diaplay 3 to the 7-segment
{
  unsigned char j;
  digitalWrite(g+w,HIGH);
  digitalWrite(d+w,HIGH);
  for(j=5;j<=7;j++)
  digitalWrite(j+w,HIGH);
  digitalWrite(dp+w,LOW);
  digitalWrite(f+w,LOW);
  digitalWrite(e+w,LOW);
}
void digital_4(int w) //diaplay 4 to the 7-segment
{
  digitalWrite(c+w,HIGH);
  digitalWrite(b+w,HIGH);
  digitalWrite(f+w,HIGH);
  digitalWrite(g+w,HIGH);
  digitalWrite(dp+w,LOW);
  digitalWrite(a+w,LOW);
  digitalWrite(e+w,LOW);
  digitalWrite(d+w,LOW);
}
void digital_5(int w) //diaplay 5 to the 7-segment
{
  unsigned char j;
  for(j = 7;j <= 9;j++)
  digitalWrite(j+w,HIGH);
  digitalWrite(c+w,HIGH);
  digitalWrite(d+w,HIGH);
  digitalWrite(dp+w,LOW);
  digitalWrite(b+w,LOW);
  digitalWrite(e+w,LOW);
}
void digital_6(int w) //diaplay 6 to the 7-segment
{
  unsigned char j;
  for(j = 7;j <= 11;j++)
  digitalWrite(j+w,HIGH);
  digitalWrite(c+w,HIGH);
  digitalWrite(dp+w,LOW);
  digitalWrite(b+w,LOW);
}
void digital_7(int w) //diaplay 7 to the 7-segment
{
  unsigned char j;
  for(j = 5;j <= 7;j++)
  digitalWrite(j+w,HIGH);
  digitalWrite(dp+w,LOW);
  for(j = 8;j <= 11;j++)
  digitalWrite(j+w,LOW);
}
void digital_8(int w) //diaplay 8 to the 7-segment
{
  unsigned char j;
  for(j = 5;j <=11;j++)
  digitalWrite(j+w,HIGH);
  digitalWrite(dp+w,LOW);
}

void digital_9(int w) // display 9 in the 9-segment
{
  digitalWrite(a+w,HIGH);
  digitalWrite(e+w,LOW);
  digitalWrite(d+w,LOW);
  digitalWrite(c+w,HIGH);
  digitalWrite(g+w,HIGH);
  digitalWrite(f+w,HIGH);
  digitalWrite(b+w,HIGH);
  digitalWrite(dp+w,LOW);

}
void digital_0(int w)
{ 
  digitalWrite (a+w,HIGH);
  digitalWrite(e+w,HIGH);
  digitalWrite(d+w,HIGH);
  digitalWrite(c+w,HIGH);
  digitalWrite(g+w,LOW);
  digitalWrite(f+w,HIGH);
  digitalWrite(b+w,HIGH);
  digitalWrite(dp+w,LOW);
}
