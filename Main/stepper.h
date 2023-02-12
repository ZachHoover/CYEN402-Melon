//Globals
#define STEPS_PER_REV 2048
#define POWERFACTOR 1024
#define DHTDELAY 60000
AccelStepper stepper(AccelStepper::HALF4WIRE, D1, D3, D2, D4);
int energy = 0;
double power = 0;
int stepperspeed = 512;
unsigned int dht_time = 0;
float temp, humid;


#define DHTPIN D5 
DHT dht(DHTPIN, DHT11);

void change_speed()
{
  stepper.setSpeed(stepperspeed);
  power = stepperspeed/(double)POWERFACTOR;
}

void read_dht()
{
  int current_time; 
  current_time = millis();
  if ((current_time > DHTDELAY + dht_time) or (dht_time == 0))
  {
    dht_time = current_time;
    temp = dht.readTemperature(true);
    humid = dht.readHumidity();
    Serial.println("Temperature:  "+String(temp)+"\tHumidity:  "+String(humid));
  }
}

//Setup
void stepper_setup()
{
  pinMode(DHTPIN, INPUT);
   stepper.setCurrentPosition(0);
   stepper.setMaxSpeed(1000);
   stepper.setSpeed(stepperspeed);
   power = stepperspeed/(double)POWERFACTOR;
   read_dht();
}

//Loop
void stepper_loop()
{
  stepper.runSpeed();
  energy = stepper.currentPosition() / STEPS_PER_REV;
  read_dht();
}
