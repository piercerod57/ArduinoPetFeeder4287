#include <avr/io.h>
int led7 = 7;
char let;

void setup() {
  // put your setup code here, to run once:
  UCSR0B = (1<<RXEN0);
  UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
  UBRR0L = 103;
  pinMode(led7, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
    //wait until new data
    while (! (UCSR0A & (1<<RXC0))){
      let = UDR0; // read in letter from sending arduino
    }

    if(let == '1'){
      Serial.println(let);
      digitalWrite(led7, HIGH); // set pin to on
      delay(200);
    }
    else if(let = '0'){
      Serial.println(let);
      digitalWrite(led7, LOW); //set pin to off
    }
    
  }
