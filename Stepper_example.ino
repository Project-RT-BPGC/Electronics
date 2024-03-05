// Sample code to run the rotary encoder on a stepper motor
// Use this to interface pid with rotary encoder output
#include <Stepper.h>

// change this to the number of steps on your motor
#define STEPS 100

// create an instance of the stepper class, specifying
// the number of steps of the motor and the pins it's
// attached to

Stepper stepper(STEPS, 8, 9, 10, 11);

// the previous reading from the analog input
int previous = 0;

//Rotary Encoder variables, set encoderPin1 and encoderPin2 as on the arduino
int encoderPin1 = 2;
int encoderPin2 = 3;
volatile int lastEncoded = 0;
volatile long encoderValue = 0;
long lastencoderValue = 0;
int lastMSB = 0;
int lastLSB = 0;

//Rotary Encoder Function
void updateEncoder(){
 int MSB = digitalRead(encoderPin1); //MSB = most significant bit
 int LSB = digitalRead(encoderPin2); //LSB = least significant bit
int encoded = (MSB << 1) |LSB; //converting the 2 pin value to single

int sum = (lastEncoded << 2) | encoded; //adding it to the previous
//encoded value
 if(sum == 0b1101 || sum == 0b0100 || sum == 0b0010 || sum == 0b1011)````
encoderValue ++;
 if(sum == 0b1110 || sum == 0b0111 || sum == 0b0001 || sum == 0b1000)
encoderValue --;
 lastEncoded = encoded; //store this value for next time
}


void setup() {
  //Rotary Encoder (no need to modify mp)
 Serial.begin (9600);
 pinMode(encoderPin1, INPUT);
 pinMode(encoderPin2, INPUT);
 digitalWrite(encoderPin1, HIGH); //turn pullup resistor on
 digitalWrite(encoderPin2, HIGH); //turn pullup resistor on
 
 //call updateEncoder() when any high/low changed seen
 //on interrupt 0 (pin 2), or interrupt 1 (pin 3)
 attachInterrupt(0, updateEncoder, CHANGE);
 attachInterrupt(1, updateEncoder, CHANGE);


//Stepper Motor part
 // set the speed of the motor to 30 RPMs
  stepper.setSpeed(30);

Serial.begin(9600);

}


void loop() {

Serial.println(encoderValue);
//Stepper motor part
  // get the sensor value
  int val = analogRead(0);

  // move a number of steps equal to the change in the
  // sensor reading
  stepper.step(val - previous);

  // remember the previous value of the sensor
  previous = val;
  
}
