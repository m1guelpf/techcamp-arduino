int ledPin = 8;
int ledPin2 = 9;
int switchPin = 10;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(ledPin2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
 if (digitalRead(switchPin) == HIGH) {
  digitalWrite(ledPin2, LOW);
  digitalWrite(ledPin, HIGH);
  delay(1000);
 } else {
  digitalWrite(ledPin, LOW);
  digitalWrite(ledPin2, HIGH);
  delay(1000);
 }
}
