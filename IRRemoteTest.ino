#include "IRremote.h"
int IRreceiver = 11;
IRrecv irrecv(IRreceiver);
decode_results results;

int ledpin[]={3,5}; //array of pins 1, 2
bool pwr = false ; // power true once , false twice or zero
bool one = false; //true once , false twice 
bool two = false; //true once , false twice 


void translateIR(){
  switch(results.value){
    case 0xFFA25D: Serial.println("POWER"); pwr = !pwr; break;
    case 0xFF30CF: Serial.println("1"); one = !one; break;
    case 0xFF18E7: Serial.println("2"); two = !two; break;
    default:Serial.println("other button"); break;
  }
  delay(100);
  }
void setup() {
Serial.begin(9600);
pinMode(ledpin[0], OUTPUT);
pinMode(ledpin[1], OUTPUT);
irrecv.enableIRIn();//start reciver
}

void loop() {
  if (irrecv.decode(&results)){
    translateIR();
    irrecv.resume();
  }

  if(pwr){
  // turn on all leds
    digitalWrite(ledpin[0], HIGH);
    digitalWrite(ledpin[1], HIGH);
    if(one){//1
      delay(100);
      digitalWrite(ledpin[0], LOW); 
    }
    if(two){//2
      delay(100);
      digitalWrite(ledpin[1], LOW); 
    }
  } else{ // not pwr
    // turn off leds
    digitalWrite(ledpin[0], LOW); 
    digitalWrite(ledpin[1], LOW); 
    // return to first state
    one = false;
    two = false;
    } 
    delay(100);
//Serial.print(pwr);
//Serial.print('\t');
//Serial.print(one);
//Serial.print('\t');
//Serial.print(two);
//Serial.println('\t');
}
