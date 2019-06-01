// Includes & Servo Naming
#include <Servo.h>
Servo ServoRotate; //Pin - 13
Servo ServoArmBase; //Pin - 12
Servo ServoArmElbow; //Pin - 11
Servo ServoArmGrasp; //Pin - 10

// Servo Pins
int const RotatePin = 13;
int const BasePin = 12;
int const ElbowPin = 11;
int const GraspPin = 10;

// Potentiometer Pins
int const Joy1X = A0;
int const Joy1Y = A1;
int const Joy2X = A2;
int const Joy2Y = A3;

// Storage variables
int Joy1XValue;
int Joy1YValue;
int Joy2XValue;
int Joy2YValue;

// Desired Angle
int Joy1XAngle;
int Joy1YAngle;
int Joy2XAngle;
int Joy2YAngle;

// Sent Angle
int Joy1XSentAngle;
int Joy1YSentAngle;
int Joy2XSentAngle;
int Joy2YSentAngle;

// Last Angle
int Joy1XLastAngle;
int Joy1YLastAngle;
int Joy2XLastAngle;
int Joy2YLastAngle;


// Setup Arm
void setup() {
  // Attach Servos
  ServoRotate.attach(RotatePin);
  ServoArmBase.attach(BasePin);
  ServoArmElbow.attach(ElbowPin);
  ServoArmGrasp.attach(GraspPin);
  // Open Serial
  Serial.begin(9600);
  // Place servo at mid point
  ServoRotate.write(94);
  ServoArmBase.write(90);
  ServoArmElbow.write(90);
  ServoArmGrasp.write(90);
  // Save angle as last angle
  Joy1XLastAngle = 0;
  Joy1YLastAngle = 90;
  Joy2XLastAngle = 90;
  Joy2YLastAngle = 90;
}

// Loop
void loop() {
//  // put your main code here, to run repeatedly:
//  potValA = analogRead(potPin1);
//  potValB = analogRead(potPin2);
//  //Serial.print("PotVal 1: ");
//  //Serial.println(potValA);
//  Serial.print("PotVal 2: ");
//  Serial.println(potValB);
//
//  angleA = map(potValA, 0, 1023, -10, 10);
//  angleB = map(potValB, 0, 1020, -10, 10);
//
//  if ( (lastAngleA + angleA) > 179 ) {
//    sentAngleA = 179;
//  }
//  else if ( (lastAngleA + angleA) < 0 ) {
//    sentAngleA = 0;
//  }
//  else {
//    sentAngleA = (lastAngleA + angleA);
//  }
//  if ( (lastAngleB + angleB) > 179 ) {
//    sentAngleB = 179;
//  }
//  else if ( (lastAngleB + angleB) < 0 ) {
//    sentAngleB = 0;
//  }
//  else {
//    sentAngleB = (lastAngleB + angleB);
//  }
//  
//  lastAngleA = sentAngleA; 
//  lastAngleB = sentAngleB;
//
//  Servo1.write(sentAngleA);
//  Servo2.write(sentAngleB);
  ServoRotate.write(94);
  delay(10);
}
