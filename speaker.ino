#include "pitches.h"
#include <avr/io.h>
#include <avr/interrupt.h>

#define SONG_LENGTH 6

void setup() 
{
  // put your setup code here, to run once:
  pinMode(8, OUTPUT);
}

//tone(pin, frequency, duration)
void loop()
{
  int melody[SONG_LENGTH]; 
  int rhythm[SONG_LENGTH];

  int melodyHappy[] = {NOTE_C3, NOTE_E3, NOTE_G4, NOTE_C4, NOTE_B4, NOTE_C3};
  int rhythmHappy[] = {8, 16, 8, 8, 16, 2};
  int melodySad[] = {NOTE_G3, NOTE_AS2, NOTE_AS2, NOTE_D3, NOTE_F3, NOTE_F3};
  int rhythmSad[] = {16, 2, 2, 16, 2, 2};

  int choice = 0;

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
    tone(8, pitch, toneDuration);
    //calculate pause time
    pauseTime = toneDuration * 1.3;
    //use delay function to pause
    delay(pauseTime);
  }
}
