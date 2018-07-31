int movementPin = 9;
int buttonPin = 10;
int buzzerPin = 8;

void setup() {
  pinMode(movementPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
  Serial.print("Door status: ");
  Serial.println(digitalRead(movementPin) == LOW ? "moving" : "static");
  if(digitalRead(movementPin) == LOW) {
    digitalWrite(buzzerPin, HIGH);
    delay(5000);
    digitalWrite(buzzerPin, LOW);
  }
  delay(1000);
}
