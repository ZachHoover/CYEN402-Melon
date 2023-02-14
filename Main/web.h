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
      return page_loggedout;
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
        if (assign_login(request->client()->remoteIP()))
        {
          request->send_P(200, "text/html", page_authed, processor);
          send_log(request->client()->remoteIP().toString()+" logged in as account "+String(credIndex));
        }
        else
        {
          send_log(request->client()->remoteIP().toString()+" attempted to login as account "+String(credIndex)+", account currently reserved for "+loggedin[credIndex].toString()+".");
          request->send_P(200, "text/html", page_loggedout, processor);
        }
      }
      else
      {
        send_log("Incorrect login from "+request->client()->remoteIP().toString()+". Attempted username: "+login_username+".");
        request->send_P(200, "text/html", page_login, processor);
      }
      credIndex = -1;
    }
    else
    {
      send_log("Invaild format for login from "+request->client()->remoteIP().toString());
      request->send_P(200, "text/html", page_login, processor);
    }
  });

  //page
  server.on("/page", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    byte index = check_login(request->client()->remoteIP());
    send_log(request->client()->remoteIP().toString()+" routed to account: "+String(index));
    request->send_P(200, "text/html", pagechange(index), processor);
  });
  
  //speed
  server.on("/speed", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    if (request->client()->remoteIP() == loggedin[3])
    {
      if (request->hasParam("Speed"))
      {
        stepperspeed = request->getParam("Speed")->value().toInt();
        change_speed();
        send_log("Power production changed to "+String(power)+" TW");
      }
    }
    else
    {
      send_log("Invaild speed request from "+request->client()->remoteIP().toString());
    }
    request->send_P(200, "text/html", page_authed, processor);
  });

  //logout
  server.on("/logout", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    byte index = check_login(request->client()->remoteIP());
    if (index >= 0 and loggedin[index] == request->client()->remoteIP())
    {
      send_log(request->client()->remoteIP().toString()+" logged out from account "+String(index));
      remove_login(index);
    }
    else
    {
      send_log("Invaild logout request from "+request->client()->remoteIP().toString());
    }
    request->send_P(200, "text/html", page_loggedout, processor);
  });
  //kick
  server.on("/kick", HTTP_GET, [](AsyncWebServerRequest *request)
  {
    Serial.println(request->hasParam("User"));
    Serial.println(check_login(request->client()->remoteIP()));
    if ((check_login(request->client()->remoteIP()) == 1))
    {
      if (request->hasParam("User"))
      {
        int acc = String(request->getParam("User")->value()).toInt();
        send_log("Department of Defense (account 1) clearing account "+String(acc)+"'s login. Cleared IP: "+loggedin[acc].toString());
        remove_login(acc);
      }
      else
      {
        send_log("Invaild kick request from "+request->client()->remoteIP().toString());
      }
    }
    else if (check_login(request->client()->remoteIP())== 2)
    {
      send_log("Department of National Intelligence (account 2) clearing Department of Defense's (account 1) login. Cleared IP: "+loggedin[1].toString());
      remove_login(1);
    }
    else
    {
      send_log("Invaild kick request from "+request->client()->remoteIP().toString());
    }
    request->send_P(200, "text/html", page_authed, processor);
  });
  server.begin();
}
