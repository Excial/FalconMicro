void led_on() {

  strip.begin();
  strip.setBrightness(BRIGHTNESS);

  strip.setPixelColor(0, strip.Color(120, 120, 120, 120));
  strip.setPixelColor(1, strip.Color(120, 120, 120, 120));
  strip.show();

}
