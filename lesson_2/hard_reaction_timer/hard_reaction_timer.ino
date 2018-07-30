#include <Time.h>

int greenLed = 8;
int redLed = 9;
int switchPin = 10;
int buttonPin = 6;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(buttonPin, INPUT);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
  int greenTime;
  int orangeTime;
  if (digitalRead(switchPin) == HIGH) {
    greenTime = 200;
    orangeTime = 400;
  } else {
    greenTime = 250;
    orangeTime = 500;
  }
  delay(5000);
  while (digitalRead(buttonPin) == LOW) {};
  green();
  int startTime = millis();
  while (digitalRead(buttonPin) == LOW) {};
  int reactionTime = millis() - startTime;
  Serial.print("Reaction (ms): ");
  Serial.println(reactionTime);
  if (reactionTime < greenTime) {
    green();
  }
  else if(reactionTime < orangeTime) {
    orange();
  }
  else {
    red();
  }
  delay(2000);
  off();
}

void green() {
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
}

void red() {
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
}

void orange() {
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
}

void off() {
   digitalWrite(redLed, LOW);
   digitalWrite(greenLed, LOW);
}

