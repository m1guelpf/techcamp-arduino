int buzzerPin = 6;
int lightPin = A0;
void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(lightPin, INPUT);
}

void loop() {
  digitalWrite(buzzerPin, analogRead(lightPin) >= 512 ? HIGH : LOW);
}
