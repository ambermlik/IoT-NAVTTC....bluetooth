#include <LiquidCrystal.h>
LiquidCrystal lcd(2, 3, 4, 5, 6, 7);
const int echoPin = 8;
const int trigPin = 9;

float duration;
float distance_cm;
float distance_inch;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
  lcd.begin(16, 2);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delay(100);
  digitalWrite(trigPin, HIGH);
  delay(100);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  
  distance_cm = duration * 0.034 / 2.0;
  distance_inch = distance_cm * 0.393701;
  
  lcd.setCursor(0, 0);
  lcd.print("Distance: ");
  lcd.print(distance_cm);
  lcd.print(" cm");
  Serial.print("Distance: " + String(distance_cm) + " cm");
  
  lcd.setCursor(0, 1);
  lcd.print("Distance: ");
  lcd.print(distance_inch);
  lcd.print(" inch");
  Serial.print("Distance: " + String(distance_inch) + " inch");
  delay(1000);
}
