#include "Keyboard.h"

void typeKey(int key) {
  Keyboard.press(key);
  delay(50);
  Keyboard.release(key);
}

void setup() {
  delay(3500);
 
  Keyboard.begin();

  delay(500);

  Keyboard.press(KEY_LEFT_GUI);
  Keyboard.press('r');
  Keyboard.releaseAll();

  typeKey(KEY_RETURN);

  delay(200);

  Keyboard.print("chrome.exe");

  typeKey(KEY_RETURN);

  delay(200);

  Keyboard.press(KEY_LEFT_CTRL);
  Keyboard.press('r');
  Keyboard.releaseAll();

  Keyboard.print("https://www.youtube.com/watch?v=dQw4w9WgXcQ");

  typeKey(KEY_RETURN);
  
  
  Keyboard.end();
}
void loop() {}
