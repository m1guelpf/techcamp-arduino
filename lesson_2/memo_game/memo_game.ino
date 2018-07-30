int greenLed = 8;
int redLed = 9;
int switchPin = 10;
int button1Pin = 6;
int button2Pin = 5;
int runs = 0;

#include <time.h>

using namespace std;

void setup() {
  pinMode(greenLed, OUTPUT);
  pinMode(switchPin, INPUT);
  pinMode(redLed, OUTPUT);
  pinMode(button1Pin, INPUT);
  pinMode(button2Pin, INPUT);
  Serial.begin(9600);
  Serial.println("Setup complete");
}

void loop() {
  bool * solution;
  solution = getSolution();
  logSolution(solution);
  outputSolution(solution);
  delay(1000);
  bool * input;
  input = getInputs();
  logInput(input);
}

bool * getSolution() {
   static bool solution[4];
   
   for (int i = 0; i < 4; ++i) {
      solution[i] = 0 == (rand() % 2);
   }

   return solution;
}

void logSolution(bool solution[]) {
  Serial.print("Solution: ");
  Serial.print(solution[0] ? "green" : "red");
  Serial.print(", ");
  Serial.print(solution[1] ? "green" : "red");
  Serial.print(", ");
  Serial.print(solution[2] ? "green" : "red");
  Serial.print(", ");
  Serial.println(solution[3] ? "green" : "red");
}

void outputSolution(bool solution[]) {
  for (int i = 0; i < 4; i++) {
    if (solution[i]) {
      green();
      delay(1000 - runs*10);
      off();
    } else {
      red();
      delay(1000 - runs*10);
      off();
    }
    delay(1000 - runs*10);
  }
}

bool * getInputs() {
  while(digitalRead(button1Pin) == LOW && digitalRead(button2Pin) == LOW){};
  bool input1 = getInput();
  while(digitalRead(button1Pin) == LOW && digitalRead(button2Pin) == LOW){};
  bool input2 = getInput();
  while(digitalRead(button1Pin) == LOW && digitalRead(button2Pin) == LOW){};
  bool input3 = getInput();
  while(digitalRead(button1Pin) == LOW && digitalRead(button2Pin) == LOW){};
  bool input4 = getInput();

  static bool input[4] = {input1, input2, input3, input4};

  return input;
}

bool getInput() {
  bool input;
  if (digitalRead(button1Pin == HIGH)) {
    input = true;
    while(digitalRead(button1Pin) == HIGH){};
  } else if (digitalRead(button2Pin == HIGH)) {
    input = true;
    while(digitalRead(button2Pin) == HIGH){};
  }

  return input;
}

void logInput(bool input[]) {
  Serial.print("Input: ");
  Serial.print(input[0] ? "green" : "red");
  Serial.print(", ");
  Serial.print(input[1] ? "green" : "red");
  Serial.print(", ");
  Serial.print(input[2] ? "green" : "red");
  Serial.print(", ");
  Serial.println(input[3] ? "green" : "red");
}

void green() {
  digitalWrite(redLed, LOW);
  digitalWrite(greenLed, HIGH);
}

void red() {
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, HIGH);
}

void orange() {
  digitalWrite(redLed, HIGH);
  digitalWrite(greenLed, HIGH);
}

void off() {
   digitalWrite(redLed, LOW);
   digitalWrite(greenLed, LOW);
}

