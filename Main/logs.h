//Globals

void send_log(String str)
{
  Serial.println(msg);
  client.print(msg);
}

//Setup
void logs_setup()
{
  Serial.println("Connecting to Logger");
  while (client.connect("96.33.128.163", 7779) == false)
  {
    Serial.println(".");
    delay(500);  
  }
  client.print("Melon");
  send_log("ESP Connected. Webpage located at:  http://"+WiFi.localIP().toString());
  Serial.println("Connected.");
  
}

//Loop
void logs_loop()
{
  
}
