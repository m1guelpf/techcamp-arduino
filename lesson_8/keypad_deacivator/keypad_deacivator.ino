#include <Base64.h>

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
const int codeLength = 4;
String code[codeLength] = {"MQ==", "Mg==", "Mw==", "Ng=="};
bool disabled[] = {false, false, false, false};

void setup () {
  for (int i = 0; i < rowCount; i++) {
    pinMode(rowPins[i], OUTPUT);
  }
  for (int i = 0; i < colCount; i++) {
    pinMode(colPins[i], INPUT);
  }
  pinMode(10, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  if (! isDisabled()) {
    digitalWrite(10, HIGH);
  }
  for (int i = 0; i < codeLength; i++) {
    char key = pressedKey();
    waitForRelease();
    char answer;
    answer = base64_decode(code[i]);
    if (key == answer) {
      digitalWrite(10,LOW);
      delay(100);
      digitalWrite(10,HIGH);
      disabled[i] = true;
    }
    waitForRelease();
  }
  if (isDisabled()) {
    digitalWrite(10, LOW);
  }
}

bool isDisabled() {
  return disabled[0] && disabled[1] && disabled[2] && disabled[3];
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

char base64_decode(String encrypted) {
  char string[4];
  encrypted.toCharArray(string, 4);
  int inputStringLength = sizeof(encrypted);
  int decodedLength = Base64.decodedLength(string, inputStringLength);

  char decodedString[decodedLength];

  Base64.decode(decodedString, string, inputStringLength);

  return decodedString[0];
}

