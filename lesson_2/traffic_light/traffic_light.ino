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
    digitalWrite(ledPin2, LOW);
    digitalWrite(ledPin, HIGH);
    Serial.println("green");
    delay(1000);
    digitalWrite(ledPin2, HIGH);
    Serial.println("orange");
    delay(1000);
    digitalWrite(ledPin, LOW);
    Serial.println("red");
    delay(1000);
    digitalWrite(ledPin2, HIGH);
    Serial.println("orange");
    delay(1000);
}
