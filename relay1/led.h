void ledsetup() {
}

int flaga_led = 0;
void led_timer()
{
  flaga_led = !flaga_led;
  digitalWrite(led_wew, flaga_led);
}

