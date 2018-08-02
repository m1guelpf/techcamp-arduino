#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, 10, NEO_RGB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.show();
  delay(1000);
  for (int i = 0; i < 5; i++) {
    strip.setPixelColor(i, strip.Color(0, 255, 0));
    strip.show();
    delay(1000);
  }
  delay(2000);
  for (int i = 0; i < 5; i++) {
    strip.setPixelColor(i, strip.Color(255, 0, 0));
  }
  strip.show();
  digitalWrite(9, HIGH);
  delay(1000);
  digitalWrite(9, LOW);
}

void loop() {
  //
}
