#include <LiquidCrystal.h>
#include "SR04.h"
#include "pitches.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define SONG_LENGTH 6
LiquidCrystal lcd(7,8,9,10,11,12);

int txpin = 6;
int rxpin = 5;
SR04 sr04 = SR04(rxpin, txpin);
int distance;
char let;

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);//We are using a 16*2 LCD display
lcd.setCursor(0,0);// set the cursor to column 0, line 1
pinMode(txpin,OUTPUT);
pinMode(rxpin,INPUT);
pinMode(4, OUTPUT);

UCSR0B = (1<<RXEN0);
  UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
  UBRR0L = 103;
}

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
      
while (! (UCSR0A & (1<<RXC0))){
      let = UDR0; // read in letter from sending arduino 
      Serial.print(let);
    }
    for(int i = 0; i < SONG_LENGTH; ++i)
  {
    if(let == '1')
    {
      melody[i] = melodyHappy[i];
      rhythm[i] = rhythmHappy[i];
      lcd.print("Dispensing for 1 sec ");
      delay(500);
      lcd.clear();
    }
    else if(let = '2'){
      melody[i] = melodyHappy[i];
      rhythm[i] = rhythmHappy[i];
      lcd.print(" Dispensing for 2 sec ");
      delay(500);
      lcd.clear();
    }
    else if(let = '9'){
      lcd.print(" FLUSHING ");
      delay(500);
      lcd.clear(); 
        if(distance >= 28){
        melody[i] = melodyHappy[i];
        rhythm[i] = rhythmHappy[i];
        lcd.print(" bottle if full ");
        delay(500);
        lcd.clear(); 
        }
        else if(distance < 28){
        melody[i] = melodySad[i];
        rhythm[i] = rhythmSad[i];
        lcd.print(" refill bottle ");
        delay(500);
        lcd.clear();
      } 
    }
  }

   int pitch;
   int beat;
   int toneDuration;
   float pauseTime;
      
  for(int i = 0; i < SONG_LENGTH; i++){
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
