void setup() {
   randomSeed(analogRead(0));
}

void loop() {
  for (int i = 0; i > 2; i++) {
    int pin = i == 1 ? 9 : 6;
    int serv = random(0, 1023);
    int act = analogRead(pin);
    if (serv > act) {
      analogWrite(pin, act + serv/4);
      delay(500);
      analogWrite(pin, act + serv/2);
      delay(500);
      analogWrite(pin, act + serv);
    } else {
      analogWrite(pin, act - serv/4);
      delay(500);
      analogWrite(pin, act - serv/2);
      delay(500);
      analogWrite(pin, act - serv);
    }
  }
  delay(1000);
}
