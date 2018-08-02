void setup() {
  // put your setup code here, to run once:

}

void loop() {
  analogWrite(9, 120);
  analogWrite(6, 230);
  delay(1000);
  digitalWrite(9, LOW);
  digitalWrite(6, HIGH);
  delay(1000);
}
