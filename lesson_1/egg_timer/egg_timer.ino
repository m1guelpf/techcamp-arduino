int startPin = 10;
int programPin = 16;
int ledPin = 9;
int waitTime = 100;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(startPin, INPUT);
  pinMode(programPin, INPUT);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
 if (digitalRead(programPin) == HIGH) {
  waitTime += 100;
  Serial.print("Wait time: ");
  Serial.println(waitTime);
  while(digitalRead(programPin) == HIGH) {};
 }
 if (digitalRead(startPin) == HIGH) {
  notifyStart();
  delay(waitTime);
  notifyEnd();
 }
}

void notifyStart() {
  Serial.println("Starting!");
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(100);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
}


void notifyEnd() {
  Serial.println("Ended");
  for (int i = 0; i < 3; i++) {
    digitalWrite(ledPin, HIGH);
    delay(200);
    digitalWrite(ledPin, LOW);
    delay(100);
  }
  waitTime = 100;
}
