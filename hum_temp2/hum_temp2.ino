#define BLYNK_MSG_LIMIT 0
//#define BLYNK_DEFAULT_PORT 8080
// #error "Compiles"
#include <EEPROM.h>
#include <Timers.h> //  my favorite timer 
Timers <7> akcja; //

#include "blynk.h" //obsługa BLYNKa
#include "led.h"
#include "dht11.h"

void setup()
{
  if (procesor == D1MINI) {
    Serial.begin(115200);  delay(100);
    Serial.println();  Serial.println(F(__FILE__));
  }
  akcja.attach(0, 3000, blynk_timer); //
  akcja.attach(2, 2000, led_timer); //
  akcja.attach(3, 1000, dht_timer);
 
  blynksetup(); // setup biblioteki BLYNK
  dhtsetup();
}

void loop()
{
  akcja.process(); // timer
  blynkakcja();    //BLYNK
}

