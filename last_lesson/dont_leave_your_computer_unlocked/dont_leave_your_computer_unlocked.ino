#include "Keyboard.h"
#include "Mouse.h"

#define blinkInterval 50
#define ledPin 17

int defaultDelay = 4;
int defaultCharDelay = 5;
int rMin = 0;
int rMax = 100;

bool ledOn = true;

void typeKey(int key){
  Keyboard.press(key);
  delay(defaultCharDelay);
  Keyboard.release(key);
}

void setup(){
  
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, HIGH);
  
    
    Keyboard.begin();
    Mouse.begin();
    
    delay(1000);

    delay(defaultDelay);
    // Lock Me 0.3 - Script opens Notepad and types a message concerning locking the computer - by SurfKahuna (RJC)terminal

    delay(defaultDelay);
    Keyboard.press(KEY_LEFT_GUI);
    Keyboard.press(114);
    Keyboard.releaseAll();

    delay(defaultDelay);
    delay(200);

    delay(defaultDelay);
    Keyboard.print("notepad.exe");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    delay(300);

    delay(defaultDelay);
    Keyboard.print("          , ,\\ ,'\\,'\\ ,'\\ ,\\ ,");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("    ,  ,\\/ \\' `'     `   '  /|");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("    |\\/                      |");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("    :                        |");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("    :                        |");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("     |                       |");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("     |                       |");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("     :               -.     _|");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("     :                \\     `.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("     |         ________:______\\");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("     :       ,'o       / o    ,");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("     :       \\       ,'-----./");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("      \\_      `--.--'        )");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("     ,` `.              ,---'|");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("     : `                     |");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("      `,-'                   |");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("      /      ,---.          ,'");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("   ,-'            `-,------'");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("   `.        ,--'");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("     `-.____/");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("            \\");

    delay(defaultDelay);
    typeKey(KEY_RETURN);
    for(int i = 0; i < 1; i++) {
      typeKey(KEY_RETURN);
    }

    delay(defaultDelay);
    Keyboard.print("I will learn to lock my computer.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("I will learn to lock my computer.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("I will learn to lock my computer.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("I will learn to lock my computer.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("I will learn to lock my computer.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("I will learn to lock my computer.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("I will learn to lock my computer.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("I will learn to lock my computer.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("I will learn to lock my computer.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    Keyboard.print("I will learn to lock my computer.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);
    for(int i = 0; i < 1; i++) {
      typeKey(KEY_RETURN);
    }

    delay(defaultDelay);
    Keyboard.print("There, just like Bart Simpson.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);
    for(int i = 0; i < 1; i++) {
      typeKey(KEY_RETURN);
    }

    delay(defaultDelay);
    Keyboard.print("Please remember to lock your computer when you step away from your desk.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);
    for(int i = 0; i < 1; i++) {
      typeKey(KEY_RETURN);
    }

    delay(defaultDelay);
    Keyboard.print("Thank you.");

    delay(defaultDelay);
    typeKey(KEY_RETURN);

    delay(defaultDelay);
    delay(100);

    delay(defaultDelay);
    Keyboard.press(KEY_LEFT_ALT);
    Keyboard.press(' ');
    Keyboard.releaseAll();

    delay(defaultDelay);
    Keyboard.print("x");
    
    /* ----- End-Script -----*/
    
    Keyboard.end();
}

void loop(){
  ledOn = !ledOn;
  digitalWrite(ledPin, ledOn);
  delay(blinkInterval);
}
