const int rowCount = 4;
const int colCount = 4;
int rowPins[rowCount] = {9, 8, 7, 6};
int colPins[colCount]= {5, 4, 3, 2};
char keymap[rowCount][colCount] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

void setup () {
  for (int i = 0; i < rowCount; i++) {
    pinMode(rowPins[i], OUTPUT);
  }
  for (int i = 0; i < colCount; i++) {
    pinMode(colPins[i], INPUT);
  }

  Serial.begin(9600);
}

void loop() {
  char key = pressedKey();
  waitForRelease();
  Serial.println(key);
  delay(100);
}

char pressedKey() {
  while (true) {
    for (int i = 0; i < rowCount; i++) {
      digitalWrite(rowPins[i], HIGH);
      for (int y = 0; y < colCount; y++) {
        if (digitalRead(colPins[y])) {
          return keymap[i][y];
        }
      }
      digitalWrite(rowPins[i], LOW);
    }
  }
}

void waitForRelease() {
  bool keyPressed = true;
  while (keyPressed) {
    keyPressed = false;
    for (int i = 0; i < rowCount; i++) {
      digitalWrite(rowPins[i], HIGH);
      for (int y = 0; y < colCount; y++) {
        if (digitalRead(colPins[y])) {
          keyPressed = true;
        }
      }
      digitalWrite(rowPins[i], LOW);
    }
  }
}

