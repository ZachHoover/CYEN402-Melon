//Globals

//Setup
void logs_setup()
{
  Serial.println("Connecting to Logger");
  while (client.connect("96.33.128.163", 7779) == false)
  {
    Serial.println(".");
    delay(500);  
  }
  client.write("Melon");
  client.write("ESP Connected. Webpage located at:  http://");
  client.print(WiFi.localIP());
  Serial.println("Connected.");
  
}

//Loop
void logs_loop()
{
  
}
