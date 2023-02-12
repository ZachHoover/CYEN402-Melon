//Globals
#include "webpage.h"
#include "passwords.h"
#include "stepper.h"
WiFiClient client;
#include "logs.h"

//WebServer Globals
AsyncWebServer server(80);
#define LED 2



const char* pagechange(short pagenum)
{
  switch(pagenum)
  {
    default:
      return page_login;
    case 0:
      return page_pm;
    case 1:
      return page_sd;
    case 2:
      return page_dni;
    case 3:
      return page_de;
    case 4:
      return page_am;
  }
  
}



String processor(const String& var)
{
  Serial.println(var);
  if (var == "POWERPROD")
  {
    return String(power) + " TW";
  }
  else if (var == "HUMIDITY")
  {
    return String(humid) + "%";
  }
  else if (var == "TEMPERATURE")
  {
    return String(temp) + "F";
  }
  return "";
}

//Setup
void web_setup()
{
  pinMode(LED,OUTPUT);
  WiFi.begin(wifissid,wifipass);
  Serial.println("Connecting to Wi-Fi");
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    delay(500);  
  }
  Serial.println("Connected");
  WiFi.mode(WIFI_STA);
  Serial.println(" Start ESP ");
  Serial.println(WiFi.localIP());
  //Routes
  //default
  server.on("/", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    client.print("Login page connection: "+request->client()->remoteIP().toString());
    request->send_P(200, "text/html", page_login, processor);
  });
  //login
  server.on("/login", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    if ((request->hasParam("User")) and (request->hasParam("Pass")))
    {
      String login_username = request->getParam("User")->value();
      String login_password = request->getParam("Pass")->value();
      if (passwords_check(login_username, login_password) and resistor_check(analogRead(A0)))
      {
        request->send_P(200, "text/html", pagechange(credIndex), processor);
        credIndex = -1;
      }
      else
      {
        request->send_P(200, "text/html", page_login, processor);
      }
    }
  });
  //de/speed
  server.on("/de/speed", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    if (request->hasParam("Speed"))
    {
      stepperspeed = request->getParam("Speed")->value().toInt();
      change_speed();
    }
    request->send_P(200, "text/html", page_de, processor);
  });
  server.begin();
}
