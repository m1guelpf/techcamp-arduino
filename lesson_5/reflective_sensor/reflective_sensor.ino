int buzzerPin = 6;
int lightPin = A0;
int buttonPin = 10;
int ledPin = 16;

void setup() {
  pinMode(buzzerPin, OUTPUT);
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(lightPin, INPUT);
  Serial.begin(9600);
}

void loop() {
  Serial.print("Intensity: ");
  Serial.println(analogRead(lightPin));
  digitalWrite(ledPin, HIGH);
  if (analogRead(lightPin) <= 200) {
    digitalWrite(buzzerPin, HIGH);
  } else {
    digitalWrite(buzzerPin, LOW);
  }
  delay(1000);
  
}
