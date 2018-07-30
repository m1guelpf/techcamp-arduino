void setup() {
  pinMode(17, OUTPUT);
}

void loop() {
 digitalWrite(17, HIGH);
 delay(500);
 digitalWrite(17, LOW);
 delay(500);
}
