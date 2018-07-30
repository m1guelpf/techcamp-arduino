void setup() {
  pinMode(9, OUTPUT);
}

void loop() {
 s();
 for (int i = 0; i < 3; i++) {
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(300);
 }
 s();
}

void s() {
  for (int i = 0; i < 3; i++) {
  digitalWrite(9, HIGH);
  delay(300);
  digitalWrite(9, LOW);
  delay(300);
 }
}

