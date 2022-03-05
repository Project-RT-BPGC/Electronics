#include <PID_v1.h>
#include "Defines.h"
 
#define PIN_INPUT 0
#define PIN_OUTPUT 3
 
//Define Variables we'll be connecting to
//double Setpoint1, Input1, Output1,Setpoint2, Input2, Output2;
 
//Specify the links and initial tuning parameters
//double Kp=2, Ki=5, Kd=1;
//PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);
 
void setup()
{
 //initialize the variables we're linked to
 Input1 = 0;
 Setpoint1 = 100;
 Input2 = 0;
 Setpoint2 = 100;
 Serial.begin(9600);
 
 //turn the PID on
// myPID.SetMode(AUTOMATIC);
}
 
void loop()
{
 Output1=motor1(Input1);
 Serial.println(Output1);
 Input1=Output1;
 Output2=motor2(Input2);
 Serial.println(Output2);
 Input2=Output2;
}
