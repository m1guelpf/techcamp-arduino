int buzzerPin = 6;
int redLedPin = 16;
int greenLedPin = 15;
int continuityPin = 9;
int switchPin = 10;

void setup() {
  pinMode(redLedPin, OUTPUT);
  pinMode(greenLedPin, OUTPUT);
  pinMode(buzzerPin, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(continuityPin, INPUT);
}

void loop() {
  if (digitalRead(continuityPin) == HIGH) {
    green();
    buzzer(false);
  } else {
    red();
    if (digitalRead(switchPin) == HIGH) {
       buzzer(true);
    }
  }
  delay(1000);
}

void red() {
  digitalWrite(redLedPin, HIGH);
  digitalWrite(greenLedPin, LOW);
}

void green() {
  digitalWrite(redLedPin, LOW);
  digitalWrite(greenLedPin, HIGH);
}

void buzzer(bool enable) {
  digitalWrite(buzzerPin, enable ? HIGH : LOW);
}

