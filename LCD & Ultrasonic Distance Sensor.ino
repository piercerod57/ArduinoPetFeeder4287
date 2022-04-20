#include <LiquidCrystal.h>
#include "SR04.h"
LiquidCrystal lcd(7,8,9,10,11,12);

int txpin = 6;
int rxpin = 5;
SR04 sr04 = SR04(rxpin, txpin);
int distance;
void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
lcd.begin(16,2);//We are using a 16*2 LCD display
lcd.setCursor(0,0);// set the cursor to column 0, line 1
pinMode(txpin,OUTPUT);
pinMode(rxpin,INPUT);
}

void loop() {
distance = sr04.Distance();
Serial.print(distance);
Serial.println("cm");
delay(500);

if (distance < 18){
  lcd.print(" bottle is fill");
  delay(500);
  lcd.clear();
  }
else if (distance >= 18 ){
  lcd.print(" refill bottle");
  delay(500);
  lcd.clear();
  }
  
}
