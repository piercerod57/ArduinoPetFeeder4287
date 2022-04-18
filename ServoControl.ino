#include <Servo.h>

Servo myservo;

int pos = 0;
int motorPin = 9;

void setup() {
  // put your setup code here, to run once:
  myservo.attach(motorPin);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(digitalRead(input1) == LOW){
    pos = 30;
    myservo.write(pos);
    delay(1000);
    pos = 0;
    myservo.write(pos);
  }
  else if(digitalRead(input2) == LOW){
    pos = 30;
    myservo.write(pos);
    delay(2000);
    pos = 0;
    myservo.write(pos);
  }
  else if(digitalRead(input3) == LOW){
    pos = 30;
    myservo.write(pos);
    delay(3000);
    pos = 0;
    myservo.write(pos);
  }
}
