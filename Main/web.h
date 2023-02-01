//Globals
#include "webpage.h"
//WebServer Globals

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

//Internal 
void WebSite(){

  server.send(200,"text/html",webSiteCont);
  
}

void webSocketEvent(uint8_t num, WStype_t type, uint8_t * payload, size_t welength)
{
  String payloadString = (const char *)payload;
  Serial.print("payloadString= ");
  Serial.println(payloadString);

  if (payloadString == "PinCheck")
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

//Setup
void web_setup()
{
  size_t sizeStr = sizeof(webSiteCont1) / sizeof(webSiteCont1[0]);
  //Serial.println(sizeStr); 
  //sizeStr = sizeof(webSiteCont2) / sizeof(webSiteCont2[0]);        
  //Serial.println(sizeStr); 
  memcpy(webSiteCont, webSiteCont1, sizeStr);
        
  pinMode(LED,OUTPUT);
  WiFi.begin(ssid,password);
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
  server.on("/",WebSite);
  server.begin();
  webSocket.begin();
  webSocket.onEvent(webSocketEvent);
}

//Loop
void web_loop()
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
