#include "LiquidCrystal.h"

#define bulb 13
#define fan 12
#define led1 11
#define led2 10
#define rs 3
#define en 4
#define d4 5
#define d5 6
#define d6 7
#define d7 8
#define pir 9
int PIR;
char val;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  pinMode(bulb, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(pir, INPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
}

void loop() {

  PIR = digitalRead(pir);

  while (Serial.available() > 0) {
    val = Serial.read();
    Serial.println(val);
    Serial.print(PIR);
    if (PIR == 1) {
      lcd.setCursor(0, 0);
      lcd.print("ROOM OCCUPIED");
      lcd.print("                                        ");
    } else {
      lcd.setCursor(0, 0);
      lcd.print("ROOM EMPTY");
      lcd.print("                               ");
      lcd.setCursor(0, 1);
      lcd.print("                                      ");
      digitalWrite(bulb, LOW);
      digitalWrite(fan, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
    }
    if (val == '2') {
      digitalWrite(bulb, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("AC Bulb ON");
    } else if (val == '1') {
      digitalWrite(bulb, LOW);
      lcd.setCursor(0, 1);
      lcd.print("                      ");
    } else if (val == '4') {
      digitalWrite(fan, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("Fan ON ");
    } else if (val == '3') {
      digitalWrite(fan, LOW);
      lcd.setCursor(0, 1);
      lcd.print("                      ");
    } else if (val == '6') {
      digitalWrite(led1, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("LED1 ON");
    } else if (val == '5') {
      digitalWrite(led1, LOW);
      lcd.setCursor(0, 1);
      lcd.print("                      ");
    } else if (val == '8') {
      digitalWrite(led2, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("LED2 ON");
    } else if (val == '7') {
      digitalWrite(led2, LOW);
      lcd.setCursor(0, 1);
      lcd.print("                      ");
    } else if (val == '0') {
      digitalWrite(bulb, HIGH);
      digitalWrite(fan, HIGH);
      digitalWrite(led1, HIGH);
      digitalWrite(led2, HIGH);
      lcd.setCursor(0, 1);
      lcd.print("All Equipment ON");


    } else if (val == '9') {
      digitalWrite(bulb, LOW);
      digitalWrite(fan, LOW);
      digitalWrite(led1, LOW);
      digitalWrite(led2, LOW);
      lcd.setCursor(0, 1);
      lcd.print("All Equipment OFF");
    }
  }
}