//Globals
#define STEPS_PER_REV 2048
#define POWERFACTOR 1024
AccelStepper stepper(AccelStepper::HALF4WIRE, D1, D3, D2, D4);
int energy = 0;
double power = 0;
int stepperspeed = 512;

//Setup
void stepper_setup()
{
   stepper.setCurrentPosition(0);
   stepper.setMaxSpeed(1000);
   stepper.setSpeed(stepperspeed);
}

//Loop
void stepper_loop()
{
  stepper.runSpeed();
  energy = stepper.currentPosition() / STEPS_PER_REV;
  power = stepperspeed/(double)POWERFACTOR;
}
