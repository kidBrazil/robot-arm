#include <Servo.h>
Servo Servo1;
Servo Servo2;
int const potPin1 = A0;
int const potPin2 = A1;
int potValA;
int potValB;
int angleA;
int sentAngleA;
int lastAngleA;
int angleB;
int lastAngleB;
int sentAngleB;

void setup() {
  // put your setup code here, to run once:
  Servo1.attach(10);
  Servo2.attach(9);
  Serial.begin(9600);
  Servo1.write(90);
  lastAngleA = 90;
  Servo2.write(90);
  lastAngleB = 90;
}

void loop() {
  // put your main code here, to run repeatedly:
  potValA = analogRead(potPin1);
  potValB = analogRead(potPin2);
  //Serial.print("PotVal 1: ");
  //Serial.println(potValA);
  Serial.print("PotVal 2: ");
  Serial.println(potValB);

  angleA = map(potValA, 0, 1023, -10, 10);
  angleB = map(potValB, 0, 1020, -10, 10);

  if ( (lastAngleA + angleA) > 179 ) {
    sentAngleA = 179;
  }
  else if ( (lastAngleA + angleA) < 0 ) {
    sentAngleA = 0;
  }
  else {
    sentAngleA = (lastAngleA + angleA);
  }
  if ( (lastAngleB + angleB) > 179 ) {
    sentAngleB = 179;
  }
  else if ( (lastAngleB + angleB) < 0 ) {
    sentAngleB = 0;
  }
  else {
    sentAngleB = (lastAngleB + angleB);
  }
  
  lastAngleA = sentAngleA; 
  lastAngleB = sentAngleB;

  Serial.print("AngVal 2: ");
  Serial.println(sentAngleB);

  Servo1.write(sentAngleA);
  Servo2.write(sentAngleB);
  delay(10);
}
