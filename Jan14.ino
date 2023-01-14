#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>
#include <Keypad.h>
#include <WebSocketsClient.h>
#include "webpage.h"

//PinPad Globals
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


//WebServer Globals
const char* ssid="Whyphi";
const char* password="ilikepie";
int LED=2;
int websockMillis=50;

unsigned long startMillis;  //some global variables available anywhere in the program
unsigned long currentMillis;
const unsigned long period = 1000*60;  // refresh time
unsigned int counter = 0;

byte flagContent = 0;

ESP8266WebServer server(80);
WebSocketsServer webSocket=WebSocketsServer(88);
String webSite,JSONtxt;
boolean LEDonoff=true;
WiFiClient client;
void WebSite(){

  server.send(200,"text/html",webSiteCont);
  
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t welength)
{
  String payloadString = (const char *)payload;
  Serial.print("payloadString= ");
  Serial.println(payloadString);

  if (payloadString == "PinCheck" && pin=="1234")
  {
    Serial.println("switch screen");
    //String str = "hello world";
    size_t sizeStr = sizeof(webSiteCont3) / sizeof(webSiteCont3[0]);
    //Serial.println(sizeStr); 
    memcpy(webSiteCont,webSiteCont3 , sizeStr);
    flagContent = 2;
    startMillis = millis();  //initial start time 
    //str.toCharArray(webSiteCont,3);
  }
  else if(type == WStype_TEXT) // receive text from cliet
  {
    byte separator=payloadString.indexOf('=');
    String var = payloadString.substring(0,separator);
    Serial.print("var=");
    Serial.println(var);
    String val = payloadString.substring(separator+1);
    Serial.print("val=");
    Serial.println(val);
    Serial.println(" ");

    if( var == "Pass" && val == "1234")
    {
        Serial.println("switch screen"); 
        //String str = "hello world";
        size_t sizeStr = sizeof(webSiteCont2) / sizeof(webSiteCont2[0]);
        //Serial.println(sizeStr); 
        memcpy(webSiteCont,webSiteCont2 , sizeStr);
        flagContent = 1;
        startMillis = millis();  //initial start time 
        //str.toCharArray(webSiteCont,3);
    }
  } 
}

void webServerSetup()
{
  size_t sizeStr = sizeof(webSiteCont1) / sizeof(webSiteCont1[0]);
  //Serial.println(sizeStr); 
  //sizeStr = sizeof(webSiteCont2) / sizeof(webSiteCont2[0]);        
  //Serial.println(sizeStr); 
  memcpy(webSiteCont, webSiteCont1, sizeStr);
        
  pinMode(LED,OUTPUT);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED)
  {
    Serial.println(".");
    delay(500);  
  }
  WiFi.mode(WIFI_STA);
  Serial.println(" Start ESP ");
  Serial.println(WiFi.localIP());
  server.on("/",WebSite);
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

void webServer()
{
  webSocket.loop();
  server.handleClient();
      
  if( flagContent == 2 )
  {
      currentMillis = millis();  //get the current "time" (actually the number of milliseconds since the program started)
      if (currentMillis - startMillis >= period)  //test whether the period has elapsed
      {
    
      Serial.println("switch screen"); 
      size_t sizeStr = sizeof(webSiteCont1) / sizeof(webSiteCont1[0]);
      memcpy(webSiteCont,webSiteCont1 , sizeStr);
      flagContent = 0;
      startMillis = currentMillis;  //IMPORTANT to save the start time of the current LED state.
      }
  }
  
  counter ++;
  //Serial.println( counter );
  
  if( flagContent == 2 )
  {
    String Data = String(counter);
    JSONtxt = "{\"Data\":\""+Data+"\"}";
    webSocket.broadcastTXT(JSONtxt);
  }
}

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
}

void setup() {
  Serial.begin(9600);
  webServerSetup();
  while (client.connect("nutzach.tk", 7777) == false)
  {
    delay(50);
  }
  client.write("Melon");
  client.write("ESP Connected.");
  
}

void loop() {
  webServer();
  pinPad();
}
