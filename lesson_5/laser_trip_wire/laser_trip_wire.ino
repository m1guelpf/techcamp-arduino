int buzzerPin = 6;
int lightPin = A0;
int buttonPin = 10;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(lightPin, INPUT);
}

void loop() {
  if (analogRead(lightPin) <= 512) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    if (digitalRead(buttonPin) == HIGH) {
      digitalWrite(buzzerPin, LOW);
      while(digitalRead(buttonPin) == HIGH){};
    }
  }
  delay(1000);
  
}
