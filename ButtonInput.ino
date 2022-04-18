int button1 = 2;
int button2 = 2;
int button3 = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP);
  pinMode(button2, INPUT_PULLUP);
  pinMode(button3, INPUT_PULLUP);

}

void loop() {
  // put your main code here, to run repeatedly:

  if(digitalRead(button1) == LOW){
    Serial.println("Dispensing for 1 second");
  }
  else if(digitalRead(button2) == LOW){
    Serial.println("Dispensing for 2 seconds");
  }
  else if(digitalRead(button3) == LOW){
    Serial.println("Dispensing for 3 seconds");
  }
  
}
