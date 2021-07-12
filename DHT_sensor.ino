#include <DHT.h>
DHT dht(2,DHT11);
void setup() {
  Serial.begin(9600);
  dht.begin();

}

void loop() {
  float h =dht.readHumidity();
  // Read temperature as celsius (the defualt)
  float t =dht.readTemperature();
  
  float tt =dht.readTemperature(true);

  float k = t+273.15;

  

  Serial.print("Humidity :");
  Serial.print(h);
  Serial.println("%");
  Serial.print("Temperature :");
  Serial.print(t);
  Serial.println("*C");
  Serial.print("Temperature :");
  Serial.print(tt);
  Serial.println(" *F");
  Serial.print(k);
  Serial.print("  *k");
  
  delay (1000);

}
