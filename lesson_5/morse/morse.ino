unsigned long signal_len,t1,t2,t3,t0;
int buttonPin = 10;
int ledPin = 16;
String code = "";
char morseCode[]={
  B00000101, // A = .-
  B00011000, // B = -...
  B00011010, // C = -.-.
  B00001100, // D = -..
  B00000010, // E = .
  B00010010, // F = ..-.
  B00001110, // G = --.
  B00010000, // H = ....
  B00000100, // I = ..
  B00010111, // J = .---
  B00001101, // K = -.-
  B00010100, // L = .-..
  B00000111, // M = --
  B00000110, // N = -.
  B00001111, // O = ---
  B00010110, // P = .--.
  B00011101, // Q = --.-
  B00001010, // R = .-.
  B00001000, // S = ...
  B00000011, // T = -
  B00001001, // U = ..-
  B00010001, // V = ...-
  B00001011, // W = .--
  B00011001, // X = -..-
  B00011011, // Y = -.--
  B00011100, // Z = --..
  B00111111, // 0 = -----
  B00101111, // 1 = .----
  B00100111, // 2 = ..---
  B00100011, // 3 = ...--
  B00100001, // 4 = ....-
  B00100000, // 5 = .....
  B00110000, // 6 = -....
  B00111000, // 7 = --...
  B00111100, // 8 = ---..
  B00111110, // 9 = ----.
};

#define NUMCHARS sizeof(morseCode)

char morseChars[]="ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);
  Serial.begin(9600);
  t3 = millis();
}

void loop()
{
  t3 = millis();
  while (digitalRead(buttonPin) == LOW) {}
  t1 = millis();
  digitalWrite(ledPin, HIGH);
  while (digitalRead(buttonPin) == HIGH) {}
  t2 = millis();
  if (t2 - t3 > 1000 && t2-t3 < 2000){
    code += ' ';
  }
  digitalWrite(ledPin, LOW); 
  signal_len = t2 - t1;
  if (signal_len > 50)
  {
    code += readio();
  }
  for (int i = 0; i < code.length(); i++) {
    handleRawInput(code.charAt(i));
  }
}

char readio()
{
  if (signal_len < 300)
  {
    return '.';
  }
  else
  {
    return '-';
  }
}

void sendMorseChar(char c)
{
  char* found= strchr(morseChars, c);
  if (found==NULL) return;
  else
  {
    byte morse= morseCode[found-morseChars];
    boolean firstBitFound=false;
    for (int i=7; i>= 0; i--) 
    {
      byte thisBit= bitRead(morse,i);
      if (firstBitFound)
      {
        if (thisBit) Serial.print('-');
        else Serial.print('.');
      }
      else if (thisBit) firstBitFound=true;
    }
  }
  Serial.print(" ");
}

char handleMorseInput(char c)
{
  static byte receiveBuf;
  if (c==0) 
  { 
    receiveBuf=1;
    return 0;
  }
  else if (c==1)
  {
    for (int i=0;i<NUMCHARS;i++)
    {
      if (receiveBuf==morseCode[i])
      {
        return morseChars[i];
      }
    }
    return('*'); 
  }
  else if (c=='.') receiveBuf= receiveBuf<<1;
  else if (c=='-') receiveBuf= (receiveBuf<<1) | 1;
  return 0;
}

void handleRawInput(char c)
{
  static boolean isMorseInput = false;
  if (c == '.' || c == '-') 
  {
    if (! isMorseInput)
    {
      isMorseInput = true;
      handleMorseInput(0);
    }
    handleMorseInput(c);
  }
  else
  {
    if (isMorseInput)
    {
      c = handleMorseInput(1);
      Serial.print(c);
      isMorseInput = false;
    }
    else if (c == ' ') Serial.print(' ');
    else if (c == '\n') Serial.println();
    else if (c > 32)
    {
      sendMorseChar(toupper(c));
    }
  }
}
