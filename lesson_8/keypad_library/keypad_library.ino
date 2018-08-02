#include <Keypad.h>

const byte rows = 4;
const byte cols = 4;
byte rowPins[rows] = {9, 8, 7, 6};
byte colPins[cols]= {5, 4, 3, 2};
char keymap[rows][cols] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};
Keypad keypad = Keypad(makeKeymap(keymap), rowPins, colPins, rows, cols);

void setup()
{
    Serial.begin(9600);
    keypad.addEventListener(keypadEvent);
}

void loop()
{
    keypad.getKey();
    delay(20);
}

void keypadEvent(KeypadEvent eKey)
{
    switch (keypad.getState())
    {
    case PRESSED:
        Serial.print("Enter: ");
        Serial.println(eKey);
        delay(10);
        break;
    }
}
