int movementPin = 9;
int magnetPin = 6;
int buttonPin = 10;
int buzzerPin = 8;
bool mounted = true;

void setup() {
  pinMode(movementPin, INPUT);
  pinMode(magnetPin, INPUT);
  pinMode(buttonPin, INPUT);
  pinMode(buzzerPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
  Serial.print("Alarm status: ");
  Serial.println(mounted ? "mounted" : "disabled");
  Serial.print("Motion status: ");
  Serial.println(digitalRead(movementPin) == LOW ? "moving" : "static");
  if (mounted) {
    if (digitalRead(magnetPin) == HIGH) {
      mounted = false;
    } else if(digitalRead(movementPin) == LOW) {
    digitalWrite(buzzerPin, HIGH);
    delay(5000);
    digitalWrite(buzzerPin, LOW);
  }
  } else {
    if (digitalRead(buttonPin) == HIGH) {
      mounted = true;
      while(digitalRead(buttonPin) == HIGH){};
    }
  }
  delay(1000);
}
