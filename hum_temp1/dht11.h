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
  Blynk.virtualWrite(V11, h);
  Blynk.virtualWrite(V12, t);
  Serial.print("Current humidity = ");
  Serial.print(h);
  Serial.print("%  ");
  Serial.print("temperature = ");
  Serial.print(t);
  Serial.println("C  ");
}

