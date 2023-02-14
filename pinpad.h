//PinPad Globals
/*
const byte n_rows = 4;
const byte n_cols = 4;
#define RES_KEY 1000
char keys[n_rows][n_cols] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};
byte colPins[n_rows] = {D3, D2, D1, D0};
byte rowPins[n_cols] = {D7, D6, D5, D4};
String pin;
Keypad myKeypad = Keypad( makeKeymap(keys), rowPins, colPins, n_rows, n_cols); 
void pinPad()
{
  char myKey = myKeypad.getKey();
  if (myKey != NULL){
    Serial.println(flagContent);
    Serial.print("Key pressed: ");
    Serial.println(myKey);
    if (flagContent != 1)
    {
      pin = "";
    }
    else if (myKey == '*')
    {
      if (pin.length() > 0)
        pin.remove(pin.length()-1);
    }
    else
    {
      pin += myKey;
    }
    Serial.print("Pin: ");
    Serial.println(pin);
  }
}*/