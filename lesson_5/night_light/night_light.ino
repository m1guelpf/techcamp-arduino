int ledPin = 10;
int lightPin = A0;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(lightPin, INPUT);
}

void loop() {
  digitalWrite(ledPin, analogRead(lightPin) <= 512 ? HIGH : LOW);
}
