#include "LiquidCrystal.h"
#include "LiquidCrystal_I2C.h"
int pir = 9;
int PIR;
int bulb = 13;
int fan = 12;
int led1 = 11;
int led2 = 10;
char val;
LiquidCrystal_I2C lcd(0 * 27, 16, 2);

void setup() {
  pinMode(9, OUTPUT);
  pinMode(bulb, OUTPUT);
  pinMode(fan, OUTPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.backlight();
}

void loop() {
  digitalWrite(9, HIGH);
  while (Serial.available()) {
    val = Serial.read();
    Serial.println(val);
  }
  if (PIR == 1) {
    lcd.setCursor(0, 0);
    lcd.print("ROOM OCCUPIED");
    lcd.print("                                ");
  }
  if (val == '2') {
    digitalWrite(bulb, HIGH);
    digitalWrite(fan, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("AC Bulb ON");
    lcd.print("                      ");
  } else if (val == '1') {
    digitalWrite(bulb, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                      ");
  } else if (val == '4') {
    digitalWrite(fan, HIGH);
    digitalWrite(bulb, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    lcd.setCursor(0, 1);
    lcd.print("Fan ON ");
    lcd.print("                      ");
  } else if (val == '3') {
    digitalWrite(fan, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                      ");
  } else if (val == '6') {
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(fan, LOW);
    digitalWrite(bulb, LOW);
    lcd.setCursor(0, 1);
    lcd.print("LED1 ON");
    lcd.print("                      ");
  } else if (val == '5') {
    digitalWrite(led1, LOW);
    lcd.setCursor(0, 1);
    lcd.print("                      ");
  } else if (val == '8') {
    digitalWrite(led2, HIGH);
    digitalWrite(led1, LOW);
    digitalWrite(fan, LOW);
    digitalWrite(bulb, LOW);
    lcd.setCursor(0, 1);
    lcd.print("LED2 ON");
    lcd.print("                      ");
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
  } else if (PIR == 0) {
    digitalWrite(bulb, LOW);
    digitalWrite(fan, LOW);
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    lcd.setCursor(0, 0);
    lcd.print("ROOM EMPTY");
    lcd.print("                      ");
    lcd.setCursor(0, 1);
    lcd.print("                      ");
  }
}