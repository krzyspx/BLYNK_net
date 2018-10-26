#include "DHT.h"
#define DHTTYPE DHT11   // DHT 11

#define dht_dpin 2
DHT dht(dht_dpin, DHTTYPE);
void dhtsetup(void)
{
  dht.begin();
}


void dht_timer() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  if (isnan(t)) ; else {
    Blynk.virtualWrite(V21, h);
    Blynk.virtualWrite(V22, t);
    Serial.print("Current humidity = ");
    Serial.print(h);
    Serial.print("%  ");
    Serial.print("temperature = ");
    Serial.print(t);
    Serial.println("C  ");
  }
}

