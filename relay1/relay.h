#define przek   0

void relaysetup(void)
{
  pinMode(przek, OUTPUT); //LED na module
  digitalWrite(przek, HIGH);
}

BLYNK_WRITE(V10) {
  if (param.asInt()) akcja.updateInterval(2, 500); else akcja.updateInterval(2, 2000);
  if (param.asInt())   digitalWrite(przek, LOW); else   digitalWrite(przek, HIGH);
  if (param.asInt())   Blynk.setProperty(V10, "color", _RED); else  Blynk.setProperty(V10, "color", _GREEN);
}

BLYNK_WRITE(V21) {
  float x = param.asFloat();
  Blynk.virtualWrite(V16, x);
  Serial.println(x);
}

BLYNK_WRITE(V11) {
  float x = param.asFloat();
  Blynk.virtualWrite(V15, x);
  Serial.println(x);
}

void relay_timer() {

  Blynk.syncVirtual(V21);
  Blynk.syncVirtual(V11);
  Serial.println("odczyt danych z serwera innych mikrokontrolerów");

}
