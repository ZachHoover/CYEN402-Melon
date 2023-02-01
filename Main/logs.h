//Globals

//Setup
void logs_setup()
{
  Serial.println("Connecting to Logger");
  while (client.connect("96.33.128.163", 7777) == false)
  {
    Serial.println(".");
    delay(500);  
  }
  client.write("Melon");
  client.write("ESP Connected.");
  Serial.print("Connected. Webpage on: ");
  Serial.println(WiFi.localIP());
}

//Loop
void logs_loop()
{
  
}
