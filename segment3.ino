#include <LiquidCrystal.h>
#include "SR04.h"
#include "pitches.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include "SevSeg.h"
SevSeg sevseg; 

#define SONG_LENGTH 6


int txpin = 6;
int rxpin = 5;
SR04 sr04 = SR04(rxpin, txpin);
int distance;
char let;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(4, OUTPUT);
pinMode(txpin,OUTPUT);
pinMode(rxpin,INPUT);

 byte numDigits = 1;
    byte digitPins[] = {};
    byte segmentPins[] = {10, 9, 11, 12, 13, 8, 7, 3};
    bool resistorsOnSegments = true;

    byte hardwareConfig = COMMON_CATHODE; 
    sevseg.begin(hardwareConfig, numDigits, digitPins, segmentPins, resistorsOnSegments);
    sevseg.setBrightness(90);
    
UCSR0B = (1<<RXEN0);
  UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
  UBRR0L = 103;
}
/*
//void buzzerPlay(int choice)
//{
  int melody[SONG_LENGTH]; 
  int rhythm[SONG_LENGTH];

  int melodyHappy[] = {NOTE_C3, NOTE_E3, NOTE_G4, NOTE_C4, NOTE_B4, NOTE_C3};
  int rhythmHappy[] = {8, 16, 8, 8, 16, 2};
  int melodySad[] = {NOTE_G3, NOTE_AS2, NOTE_AS2, NOTE_D3, NOTE_F3, NOTE_F3};
  int rhythmSad[] = {16, 2, 2, 16, 2, 2};

//  for(int i = 0; i < SONG_LENGTH; ++i)
//  {
//    if(choice == 1)
//    {
//      melody[i] = melodyHappy[i];
//      rhythm[i] = rhythmHappy[i];
//    }
//    else
//    {
//      melody[i] = melodySad[i];
//      rhythm[i] = rhythmSad[i];
//    }
//  }
  
  int pitch;
  int beat;
  int toneDuration;
  float pauseTime;
*/


void loop() {
      distance = sr04.Distance();
      Serial.print(distance);
      Serial.println("cm");
      delay(500);
      int melody[SONG_LENGTH]; 
  int rhythm[SONG_LENGTH];

  int melodyHappy[] = {NOTE_C3, NOTE_E3, NOTE_G4, NOTE_C4, NOTE_B4, NOTE_C3};
  int rhythmHappy[] = {8, 16, 8, 8, 16, 2};
  int melodySad[] = {NOTE_G3, NOTE_AS2, NOTE_AS2, NOTE_D3, NOTE_F3, NOTE_F3};
  int rhythmSad[] = {16, 2, 2, 16, 2, 2};

  int choice;

  
      
//while (! (UCSR0A & (1<<RXC0))){
//      let = UDR0; // read in letter from sending arduino 
//      break;
//      Serial.print(let);}
//for(int i = 0; i < SONG_LENGTH; ++i) {
//    if(let == '1') {
//      sevseg.setNumber(1);
//        sevseg.refreshDisplay();   
//      buzzerPlay(1);//pass in choice
//    } else if(let = '2'){
//      sevseg.setNumber(2);
//        sevseg.refreshDisplay();   
//    }
//    else if(let = '9'){
//   buzzerPlay(0);//pass in choice; 
        if(distance >= 28){
//        buzzerPlay(0);//pass in choice; 
          choice = 0;
          sevseg.setNumber(8);
          sevseg.refreshDisplay();
        }
        else if(distance < 28){
          choice = 1;
//        buzzerPlay(1);//pass in choice
          sevseg.setNumber(9);
          sevseg.refreshDisplay();
      } 
  for(int i = 0; i < SONG_LENGTH; ++i)
  {
    if(choice == 1)
    {
      melody[i] = melodyHappy[i];
      rhythm[i] = rhythmHappy[i];
    }
    else
    {
      melody[i] = melodySad[i];
      rhythm[i] = rhythmSad[i];
    }
  }
  
  int pitch;
  int beat;
  int toneDuration;
  float pauseTime;
  
  for(int i = 0; i < SONG_LENGTH; i++)
  {
    pitch = melody[i];
    beat = rhythm[i];
    //calculate the tone duration
    toneDuration = 1000 / beat;
    //play the tone
    tone(4, pitch, toneDuration);
    //calculate pause time
    pauseTime = toneDuration * 1.3;
    //use delay function to pause
    delay(pauseTime);
  }
    }
//  }
