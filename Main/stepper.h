//Globals
AccelStepper stepper(AccelStepper::HALF4WIRE, D1, D3, D2, D4);
//Setup
void stepper_setup()
{
   stepper.setMaxSpeed(1000);
   stepper.setSpeed(200);
}

//Loop
void stepper_loop()
{
  stepper.runSpeed();
}
