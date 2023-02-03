//Globals
char* username[5];
char* password[5];
short resistor[5];
byte credIndex = -1;
#define RESTOL 3

//Password Check
bool passwords_check(String user, String pass)
{
  for (byte i=0; i<user.length(); i++)
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
  username[0] = "test";
  password[0] = "1234";
  resistor[0] = 900;
  
}

//Loop
void passwords_loop()
{
  
}
