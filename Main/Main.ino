#include <ESP8266WiFi.h>
#include <WebSocketsServer.h>
#include <ESP8266WebServer.h>
#include <Keypad.h>
#include <WebSocketsClient.h>
#include <AccelStepper.h>

const char* wifissid="Whyphi";
const char* wifipass="ilikepie";

//Modules
#include "web.h"
#include "stepper.h"

#include "logs.h"


void setup() {
  Serial.begin(9600);
  web_setup();
  logs_setup();
  passwords_setup();
  stepper_setup();
}

void loop() {
  web_loop();
  passwords_loop();
  stepper_loop();
  logs_loop();
}
