int buzzerPin = 6;
int continuityPin = 9;
int lives = 1;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(continuityPin, INPUT);
}

void loop() {
  if (digitalRead(continuityPin) == HIGH) {
    lives--;
    if (lives <= 0) {
      buzzer(true);
      delay(3000);
      buzzer(false);
      lives = 3;
    }
    while (digitalRead(continuityPin) == HIGH){};
  }
  delay(1000);
}

void buzzer(bool enable) {
  digitalWrite(buzzerPin, enable ? HIGH : LOW);
}

