// Includes & Servo Naming
#include <Servo.h>
Servo ServoRotate; //Pin - 13
Servo ServoArmBase; //Pin - 12
Servo ServoArmElbow; //Pin - 11
Servo ServoArmGrasp; //Pin - 10

// Servo Pins
int const RotatePin = 2;
int const BasePin = 3;
int const ElbowPin = 4;
int const GraspPin = 5;

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
int Joy1YSentAngle;
int Joy2XSentAngle;
int Joy2YSentAngle;

// Last Angle
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
  ServoRotate.write(90);
  ServoArmBase.write(90);
  ServoArmElbow.write(90);
  ServoArmGrasp.write(90);
  // Save angle as last angle
  Joy1YLastAngle = 90;
  Joy2XLastAngle = 90;
  Joy2YLastAngle = 90;
}

// Loop
void loop() {
  //  // put your main code here, to run repeatedly:
  // Read Potentiometer values
  Joy1XValue = analogRead(Joy1X);
  Joy1YValue = analogRead(Joy1Y);
  Joy2XValue = analogRead(Joy2X);
  Joy2YValue = analogRead(Joy2Y);

  // Joystick 1 X  Base Rotation ----------------------------/
  ServoRotate.attach(RotatePin);
  Joy1XAngle = map(Joy1XValue, 0, 1023, 0, 190); // Map straight to Servo output
  ServoRotate.write(Joy1XAngle);

  // Joystick 1 Y  Arm Raise / Lower ----------------------------/
  Joy1YAngle = map(Joy1YValue, 0, 1005, -5, 5);
  Joy1YSentAngle = CheckLimits(Joy1YLastAngle, Joy1YAngle);
  // Write to servo
  ServoArmBase.write(Joy1YSentAngle);
  // Save Servo Position
  Joy1YLastAngle = Joy1YSentAngle;

  // Joystick 2 X Elbow Raise / Lower ----------------------------/
  Joy2XAngle = map(Joy2XValue, 0, 1000, -10, 10);
  Joy2XSentAngle = CheckLimits(Joy2XLastAngle, Joy2XAngle);
  // Write to servo
  ServoArmElbow.write(Joy2XSentAngle);
  // Save Servo Position
  Joy2XLastAngle = Joy2XSentAngle;

  // Joystick 1 Y  Arm Raise / Lower ----------------------------/
  Joy2YAngle = map(Joy2YValue, 0, 1000, -10, 10);
  Joy2YSentAngle = CheckLimits(Joy2YLastAngle, Joy2YAngle);
  // Write to servo
  ServoArmGrasp.write(Joy2YSentAngle);
  // Save Servo Position
  Joy2YLastAngle = Joy2YSentAngle;
  // Delay
  delay(30);
}

// Check to ensure limits are not passed on Servo
int CheckLimits(int lastAngle, int newAngle) {
  int returnAngle;
  if ((lastAngle + newAngle) >= 180 ){
    returnAngle = 180;
  }
  else if ((lastAngle + newAngle) <= 0 ) {
    returnAngle = 0;
  }
  else {
    returnAngle = lastAngle + newAngle;
  }
  return returnAngle;
}
