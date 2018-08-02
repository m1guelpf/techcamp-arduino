#include <Adafruit_NeoPixel.h>

int c;
bool asc = true;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, 10, NEO_RGB + NEO_KHZ800);

void setup() {
  strip.begin();

  c = 0;

  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
  for (int i = 0; i < 255; i++) {
     strip.setPixelColor(0, strip.Color(i,i,i));
     delay(10);
     strip.show();
  }
  for (int i = 0; i < 255; i++) {
     strip.setPixelColor(1, strip.Color(i,i,i));
     delay(10);
     strip.show();
  }
  for (int i = 0; i < 255; i++) {
     strip.setPixelColor(2, strip.Color(i,i,i));
     delay(10);
     strip.show();
  }
  for (int i = 0; i < 255; i++) {
     strip.setPixelColor(3, strip.Color(i,i,i));
     delay(10);
     strip.show();
  }
  for (int i = 0; i < 255; i++) {
     strip.setPixelColor(4, strip.Color(i,i,i));
     delay(10);
     strip.show();
  }
    
    strip.show();
}

void setStatus(int c, bool& asc) {
  if (c == 255) {
      asc = false;
    } else if (c == 0) {
      asc = true;
    }
}

void mutateColor(int& c, bool asc) {
  asc ? c++ : c--;
}

