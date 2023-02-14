#include <ESP8266WiFi.h>
#include <Keypad.h>
#include <WebSocketsClient.h>
#include <AccelStepper.h>
#include <ESPAsyncTCP.h>
#include <ESPAsyncWebServer.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>


const char* wifissid="Whyphi";
const char* wifipass="ilikepie";

//Modules
#include "web.h"


void setup() {
  Serial.begin(9600);
  web_setup();
  logs_setup();
  passwords_setup();
  stepper_setup();
}

void loop() {
  //web_loop();
  passwords_loop();
  stepper_loop();
  logs_loop();
}
