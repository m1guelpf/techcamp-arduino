int buttonPin = 10;
int button2Pin = 16;
int ledPin = 9;
int intensity = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(buttonPin, INPUT);
  pinMode(button2Pin, INPUT);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
 while(digitalRead(buttonPin) == HIGH) {
  if (intensity < 1024) {
    intensity += 1;
  }
  Serial.print("Intensity level: ");
  Serial.println(intensity);
  delay(100);
  analogWrite(ledPin, intensity);
 }

 if(digitalRead(button2Pin) == HIGH) {
  intensity = 0;
  Serial.println("Intensity level: 0");
 }
 analogWrite(ledPin, intensity);
}
