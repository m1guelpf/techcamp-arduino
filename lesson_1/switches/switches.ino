int switchPin = 10;
int ledPin = 9;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
}

void loop() {
 bool switchOn = digitalRead(switchPin) == HIGH;

 if (switchOn) {
  digitalWrite(ledPin, HIGH);
  delay(1000);
  digitalWrite(ledPin, LOW);
 }
}

