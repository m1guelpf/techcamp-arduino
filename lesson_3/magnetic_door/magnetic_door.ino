int magneticPin = 9;
int buttonPin = 10;
int buzzerPin = 8;

void setup() {
  pinMode(magneticPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
  Serial.print("Door status: ");
  Serial.println(digitalRead(magneticPin) == HIGH ? "closed" : "open");
  if(digitalRead(magneticPin) == LOW) {
    digitalWrite(buzzerPin, HIGH);
  } else {
     digitalWrite(buzzerPin, LOW);
  }
  if (digitalRead(buttonPin) == HIGH) {
     digitalWrite(buzzerPin, LOW);
  }
  delay(1000);
}
