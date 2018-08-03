#define OSX 0
#define WINDOWS 1
#define UBUNTU 2

#include "Keyboard.h"

int platform = OSX;

void setup() {
  pinMode(2, INPUT_PULLUP);
  Keyboard.begin();
}

void loop() {
  delay(1000);

  switch (platform) {
    case OSX:
      Keyboard.press(KEY_LEFT_GUI);
      Keyboard.press(KEY_LEFT_SHIFT);
      Keyboard.press('Q');
      delay(100);
      Keyboard.releaseAll();
      Keyboard.write(KEY_RETURN);
      break;
    case WINDOWS:
      Keyboard.press(KEY_LEFT_ALT);
      Keyboard.press(KEY_F4);
      delay(100);
      Keyboard.releaseAll();
      delay(2000);
      Keyboard.write(KEY_RETURN);
      Keyboard.releaseAll();
      break;
  }
  while (true);
}
