int switch1Pin = 10;
int switch2Pin = 16;
int ledPin = 9;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(switch1Pin, INPUT);
  pinMode(switch2Pin, INPUT);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
 if (digitalRead(switch1Pin) == HIGH) {
  Serial.println("short beep");
  digitalWrite(9, HIGH);
  delay(300);
  digitalWrite(9, LOW);
  delay(300);
 }

 if (digitalRead(switch2Pin) == HIGH) {
  Serial.println("long beep");
  digitalWrite(9, HIGH);
  delay(500);
  digitalWrite(9, LOW);
  delay(300);
 }
}

