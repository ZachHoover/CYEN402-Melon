//Globals
char* username[5];
char* password[5];
short resistor[5];
byte credIndex = -1;
#define RESTOL 5

IPAddress loggedin[5];

bool assign_login(IPAddress adr)
{
  if (credIndex < 0)
  {
    return false;
  }
  if ((loggedin[credIndex] == IPAddress()) or (loggedin[credIndex] == adr))
  {
    loggedin[credIndex] = adr;
    return true;
  }
  return false;
}

byte check_login(IPAddress adr)
{
  for (byte i=0; i<5; i++)
  {
    if (loggedin[i] == adr)
    {
      return i;
    }
  }
  return -1;
}

void remove_login(int acc)
{
  if ((acc >= 0) and (acc < 5))
  {
    loggedin[acc] = IPAddress();
  }
}

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
  Serial.print("Current resistor value:  ");
  Serial.println(val);
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
