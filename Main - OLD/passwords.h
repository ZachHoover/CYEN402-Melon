//Globals
char* username[5];
char* password[5];
short resistor[5];
byte credIndex = -1;
#define RESTOL 3

//Password Check
bool passwords_check(String user, String pass)
{
  for (byte i=0; i<5; i++)
  {
    if (String(username[i]) == user)
    {
      credIndex = i;
      break;
    }
  }
  if (String(password[credIndex]) == pass)
  {
    return true;
  }
  credIndex = -1;
  return false;
}

//Resistor Check
bool resistor_check(short val)
{
  if (credIndex < 0)
  {
    return false;
  }
  if ((val > (resistor[credIndex] - RESTOL)) and (val < (resistor[credIndex] + RESTOL)))
  {
    return true;
  }
  return false;
  
}

//Setup
void passwords_setup()
{
  username[0] = "pm";
  password[0] = "1234";
  resistor[0] = 900;
  
  username[1] = "sd";
  password[1] = "1234";
  resistor[1] = 900;
  
  username[2] = "di";
  password[2] = "1234";
  resistor[2] = 900;
  
  username[3] = "de";
  password[3] = "1234";
  resistor[3] = 900;
  
  username[4] = "am";
  password[4] = "1234";
  resistor[4] = 900;
  
}

//Loop
void passwords_loop()
{
  
}
