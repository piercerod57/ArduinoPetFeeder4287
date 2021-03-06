#include <avr/io.h>

int button1 = 3;
int button2 = 5;



void usart_init (void)
{
  UCSR0B = (1<<TXEN0);
  UCSR0C = (1<<UCSZ01)|(1<<UCSZ00);
  //baud rate = 9600bps
  UBRR0L = 103;
}



void usart_send (unsigned char ch)
{
  while (! (UCSR0A & (1<<UDRE0)));
     //wait until UDR0 is empty
   UDR0 = ch;//transmit ch
}



void setup() {
  // put your setup code here, to run once:
  usart_init();
  pinMode(button1, INPUT_PULLUP); // initialize state of buttons
  pinMode(button2, INPUT_PULLUP);
  Serial.begin(9600);

}


void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(button1) == LOW){
    usart_send('1'); // send 1 for on
    Serial.println('1');
  }
  else if(digitalRead(button2) == LOW){
    usart_send('0');  // send 0 for off
    Serial.println('0');

  }
  
}
