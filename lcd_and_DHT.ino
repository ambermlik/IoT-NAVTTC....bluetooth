#include<LiquidCrystal.h>
#include<DHT.h>

LiquidCrystal lcd(3,4,5,6,7,8);
DHT dht(9, DHT11);


void setup() {
     dht.begin();
    lcd.begin(16,2);

}

void loop() {
   float h  = dht.readHumidity();
   float t = dht.readTemperature();

  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  Serial.println("Humidity: " +String(h) +"%");
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  lcd.print("Temperature: " + String(t) +"*C");
  delay(1000);
}
