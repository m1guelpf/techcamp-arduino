#include <Adafruit_NeoPixel.h>

int buttonPin = 9;
Adafruit_NeoPixel strip = Adafruit_NeoPixel(5, 10, NEO_RGB + NEO_KHZ800);

void setup() {
  randomSeed(analogRead(0));

  strip.begin();

  pinMode(buttonPin, INPUT);

  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
  delay(random(1000, 5000));
  strip.setPixelColor(random(0, 4), strip.Color(random(0, 255), random(0, 255), random(0, 255)));
  strip.show();
  int startTime = millis();
  while (digitalRead(buttonPin) == LOW) {};
  int reactionTime = millis() - startTime;
  Serial.print("Reaction seconds: ");
  Serial.println(reactionTime);
  strip.clear();
  if (reactionTime < 250) {
    for (int i = 0; i < 5; i++) {
      strip.setPixelColor(i, strip.Color(255, 0, 0));
    }
  }
  else if(reactionTime < 500) {
    for (int i = 0; i < 5; i++) {
     strip.setPixelColor(i, strip.Color(255, 255, 0));
    }
  }
  else {
    for (int i = 0; i < 5; i++) {
      strip.setPixelColor(i, strip.Color(0, 255, 0));
    }
  }
  strip.show();
  delay(2000);
  strip.clear();
}

