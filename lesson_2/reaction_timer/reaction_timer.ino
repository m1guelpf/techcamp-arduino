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
  delay(5000);
  green();
  int startTime = millis();
  while (digitalRead(buttonPin) == LOW) {};
  int reactionTime = millis() - startTime;
  Serial.print("Reaction seconds: ");
  Serial.println(reactionTime);
  if (reactionTime < 250) {
    green();
  }
  else if(reactionTime < 500) {
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

