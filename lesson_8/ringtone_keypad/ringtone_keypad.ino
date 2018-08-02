const int tonePin = 10;
char *marioSong = "smb:d=4,o=5,b=100:16e6,16e6,32p,8e6,16c6,8e6,8g6,8p,8g,8p,8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,16p,8c6,16p,8g,16p,8e,16p,8a,8b,16a#,8a,16g.,16e6,16g6,8a6,16f6,8g6,8e6,16c6,16d6,8b,8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,8p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16c7,16p,16c7,16c7,p,16g6,16f#6,16f6,16d#6,16p,16e6,16p,16g#,16a,16c6,16p,16a,16c6,16d6,8p,16d#6,8p,16d6,8p,16c6";
char *starwarsSong = "Imperial:d=4,o=5,b=100:e,e,e,8c,16p,16g,e,8c,16p,16g,e,p,b,b,b,8c6,16p,16g,d#,8c,16p,16g,e,8p";
char *backtothefutureSong = "BackFuture:d=16,o=5,b=200:4g.,p,4c.,p,2f#.,p,g.,p,a.,p,8g,p,8e,p,8c,p,4f#,p,g.,p,a.,p,8g.,p,8d.,p,8g.,p,8d.6,p,4d.6,p,4c#6,p,b.,p,c#.6,p,2d.6";
char *batmanSong = "Batman:d=8,o=5,b=180:d,d,c#,c#,c,c,c#,c#,d,d,c#,c#,c,c,c#,c#,d,d#,c,c#,c,c,c#,c#,f,p,4f";
char *cantinaSong = "Cantina:d=8,o=5,b=250:a,p,d6,p,a,p,d6,p,a,d6,p,a,p,g#,4a,a,g#,a,4g,f#,g,f#,4f.,d.,16p,4p.,a,p,d6,p,a,p,d6,p,a,d6,p,a,p,g#,a,p,g,p,4g.,f#,g,p,c6,4a#,4a,4g";
char *finalcountdownSong = "FinalCountdown:d=16,o=5,b=125:b,a,4b,4e,4p,8p,c6,b,8c6,8b,4a,4p,8p,c6,b,4c6,4e,4p,8p,a,g,8a,8g,8f#,8a,4g.,f#,g,4a.,g,a,8b,8a,8g,8f#,4e,4c6,2b.,b,c6,b,a,1b";
char *miSong = "MissionImpossible:d=16,o=5,b=100:32d,32d#,32d,32d#,32d,32d#,32d,32d#,32d,32d,32d#,32e,32f,32f#,32g,g,8p,g,8p,a#,p,c6,p,g,8p,g,8p,f,p,f#,p,g,8p,g,8p,a#,p,c6,p,g,8p,g,8p,f,p,f#,p,a#,g,2d,32p,a#,g,2c#,32p,a#,g,2c,p,a#4,c";
char *supermanSong = "SuperMan:d=8,o=6,b=180:g5,g5,g5,4c,c,2g,p,g,a.,16g,f,1g,p,g5,g5,g5,4c,c,2g,p,g,a.,16g,f,a,2g.,4p,c,c,c,2b.,4g.,c,c,c,2b.,4g.,c,c,c,b,a,b,2c7,c,c,c,c,c,2c.";
char *titanicSong = "Titanic:d=8,o=6,b=120:c,d,2e.,d,c,d,g,2g,f,e,4c,2a5,g5,f5,16d5,16e5,2d5,p,c,d,2e.,d,c,d,g,2g,e,g,2a,2g,16d,16e,2d.";

#define OCTAVE_OFFSET 0

int notes[] = { 0,
262, 277, 294, 311, 330, 349, 370, 392, 415, 440, 466, 494,
523, 554, 587, 622, 659, 698, 740, 784, 831, 880, 932, 988,
1047, 1109, 1175, 1245, 1319, 1397, 1480, 1568, 1661, 1760, 1865, 1976,
2093, 2217, 2349, 2489, 2637, 2794, 2960, 3136, 3322, 3520, 3729, 3951
};

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

void setup()
{
  for (int i = 0; i < rowCount; i++) {
    pinMode(rowPins[i], OUTPUT);
  }
  for (int i = 0; i < colCount; i++) {
    pinMode(colPins[i], INPUT);
  }

  Serial.begin(9600);
}

#define isdigit(n) (n >= '0' && n <= '9')

void play(char *p)
{
  byte default_dur = 4;
  byte default_oct = 6;
  int bpm = 63;
  int num;
  long wholenote;
  long duration;
  byte note;
  byte scale;
  // format: d=N,o=N,b=NNN:
  while(*p != ':') p++;
  p++;
  if(*p == 'd')
  {
    p++; p++;
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    if(num > 0) default_dur = num;
    p++;
  }

  Serial.print("ddur: ");
  Serial.println(default_dur, 10);
  if(*p == 'o')
  {
    p++; p++;
    num = *p++ - '0';
    if(num >= 3 && num <=7) default_oct = num;
    p++;
  }
  Serial.print("doct: ");
  Serial.println(default_oct, 10);
  if(*p == 'b')
  {
    p++; p++;
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    bpm = num;
    p++;
  }

  Serial.print("bpm: ");
  Serial.println(bpm, 10);
  wholenote = (60 * 1000L / bpm) * 4;
  Serial.print("whole note: ");
  Serial.println(wholenote, 10);
  while(*p)
  {
    num = 0;
    while(isdigit(*p))
    {
      num = (num * 10) + (*p++ - '0');
    }
    
    if(num) duration = wholenote / num;
    else duration = wholenote / default_dur;
    note = 0;

    switch(*p)
    {
      case 'c':
        note = 1;
        break;
      case 'd':
        note = 3;
        break;
      case 'e':
        note = 5;
        break;
      case 'f':
        note = 6;
        break;
      case 'g':
        note = 8;
        break;
      case 'a':
        note = 10;
        break;
      case 'b':
        note = 12;
        break;
      case 'p':
      default:
        note = 0;
    }
    p++;
    if(*p == '#')
    {
      note++;
      p++;
    }
    if(*p == '.')
    {
      duration += duration/2;
      p++;
    }
    if(isdigit(*p))
    {
      scale = *p - '0';
      p++;
    }
    else
    {
      scale = default_oct;
    }

    scale += OCTAVE_OFFSET;

    if(*p == ',')
      p++;
    if(note)
    {
      Serial.print("Playing: ");
      Serial.print(scale, 10); Serial.print(' ');
      Serial.print(note, 10); Serial.print(" (");
      Serial.print(notes[(scale - 4) * 12 + note], 10);
      Serial.print(") ");
      Serial.println(duration, 10);
      tone(tonePin, notes[(scale - 4) * 12 + note]);
      delay(duration);
      noTone(tonePin);
    }
    else
    {
      Serial.print("Pausing: ");
      Serial.println(duration, 10);
      delay(duration);
    }
  }
}

void loop()
{
    char key = pressedKey();
    waitForRelease();
    switch (key){
      case '1':
        play(marioSong);
        break;

      case '2':
        play(starwarsSong);
        break;

      case '3':
        play(backtothefutureSong);
        break;

      case '4':
        play(batmanSong);
        break;

      case '5':
        play(cantinaSong);
        break;

      case '6':
        play(finalcountdownSong);
        break;

      case '7':
        play(miSong);
        break;

      case '8':
        play(supermanSong);
        break;

      case '9':
        play(titanicSong);
        break;
    }
    waitForRelease();
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

