void setup() {
  pinMode(10, OUTPUT);
}

void loop() {
  if (digitalRead(9) == LOW) {
    digitalWrite(10, HIGH);
  } else {
    digitalWrite(10, LOW);
  }
  delay(1000);
}
