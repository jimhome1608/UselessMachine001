

#include <Servo.h> 
#include "musical_notes.h"  

#define SWITCH 7

 
Servo myservo;               
int ServoPos = 180;    // variable to store the servo position 
int speakerPin = 3; 
  
void setup() 
{ 
 Serial.begin(9600); 
 pinMode(SWITCH,INPUT);
 pinMode(speakerPin, OUTPUT);
 myservo.attach(9);  // attaches the servo on pin 9 to the servo object 
 gotoPos(0);
} 

void ohhh() {
  for (int i=1000; i<2000; i=i*1.02) {
    if (digitalRead(SWITCH) == LOW) return;
    beep(speakerPin,i,10);
  }
  for (int i=2000; i>1000; i=i*.98) {
    if (digitalRead(SWITCH) == LOW) return;
    beep(speakerPin,i,10);
  }
}

void uhoh() {
  for (int i=1000; i<1244; i=i*1.01) {
    beep(speakerPin,i,30);
  }
  delay(200);
  for (int i=1244; i>1108; i=i*.99) {
    beep(speakerPin,i,30);
  }
}

void laugh() {
  for (int i=1000; i<2000; i=i*1.10) {
    if (digitalRead(SWITCH) == HIGH) return;
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    if (digitalRead(SWITCH) == HIGH) return;
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i<2000; i=i*1.10) {
    if (digitalRead(SWITCH) == HIGH) return;
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    if (digitalRead(SWITCH) == HIGH) return;
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i<2000; i=i*1.10) {
    if (digitalRead(SWITCH) == HIGH) return;
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    if (digitalRead(SWITCH) == HIGH) return;
    beep(speakerPin,i,10);
  }
  delay(50);
    for (int i=1000; i<2000; i=i*1.10) {
    if (digitalRead(SWITCH) == HIGH) return;
    beep(speakerPin,i,10);
  }
  delay(50);
  for (int i=1000; i>500; i=i*.90) {
    if (digitalRead(SWITCH) == HIGH) return;
    beep(speakerPin,i,10);
  }
  delay(50);
}

void beep (int speakerPin, float noteFrequency, long noteDuration)
{    
  int x;
  // Convert the frequency to microseconds
  float microsecondsPerWave = 1000000/noteFrequency;
  // Calculate how many HIGH/LOW cycles there are per millisecond
  float millisecondsPerCycle = 1000/(microsecondsPerWave * 2);
  // Multiply noteDuration * number or cycles per millisecond
  float loopTime = noteDuration * millisecondsPerCycle;
  // Play the note for the calculated loopTime.
  for (x=0;x<loopTime;x++)   
          {   
              digitalWrite(speakerPin,HIGH); 
              delayMicroseconds(microsecondsPerWave); 
              digitalWrite(speakerPin,LOW); 
              delayMicroseconds(microsecondsPerWave); 
          } 
} 

void gotoPos(int i)
{
   if (i < 0)
     i = 0;
   if (i > 103)
     i = 103;
   if (ServoPos == i)
     return;
   ServoPos = i;
   myservo.write(ServoPos);
}

void attackSwitch()
{
  int i;
  i =  ServoPos +1;
  gotoPos(i);
  if (i== 20) {
   gotoPos(130);  
   ohhh();
  }
  
}  

void retreatSwitch()
{
  int i;
  i =  ServoPos -1;
  gotoPos(i);
  if (i== 20) {
   gotoPos(0);  
   laugh();
  }
}  

void JustLook()
{
   gotoPos(35);
   delay(1000);
   gotoPos(0);
}  
 
void loop() 
{ 
 //return;
  if (digitalRead(SWITCH) == HIGH) {
    attackSwitch();
  }
  else {
   retreatSwitch();
   if (ServoPos ==0) {
       if (random(50000) == 123)
          JustLook();
   }  
  }
  delay(1);
} 
