#include <Servo.h>
#include <SoftwareSerial.h> //this one is for the bluetooth module

int enA = 9; //these three are for defining the motor pins
int in1 = 8;
int in2 = 7;

Servo Mservo; //Defines the servos
Servo Gservo;

SoftwareSerial Blue(10, 11); //Defines the pins for the bluetooth modules (pins 10 and 11)
int state = 0; //a variable for inputting commands


void setup() {

  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT); //Defines the states of the motor
  pinMode(in2, OUTPUT);
 
  // Turn off motors - Initial state
  //digitalWrite(in1, LOW);
  //digitalWrite(in2, LOW);

  Mservo.attach(6); //States the pins for servo motors
  Gservo.attach(5);

  Serial.begin(9600);
  Blue.begin(9600);
  Serial.println("Ready to connect\nDefault password is 1234 or 0000");

  Mservo.write(90); //Moves the servos 90 degrees
  Gservo.write(90);

  analogWrite(enA, 255); //Turns the motor on at max speed
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

}

void loop() {

if(Blue.available())
  state = Blue.read(); //everything after here makes it so when a number is inputed the servos move a certain amount

  if (state == '0') {
    Mservo.write(90);
    Gservo.write(90);
    Serial.println("Both servos at 90");
   
  } else if (state == '1') {
    Mservo.write(150);
    Serial.println("Motor servo at 150");
   
  } else if (state == '2') {
    Mservo.write(30);
    Serial.println("Motor servo at 60");
   
  } else if (state == '3') {
    Gservo.write(150);
    Serial.println("Elevator servo at 150");
   
  } else if (state == '4') {
    Gservo.write(90);
    Serial.println("Elevator servo at 90");
   
  } else if (state == '7') {
    Gservo.write(90);
    Mservo.write(90);
    analogWrite(enA,0);
    Serial.println("All motors leveled and propeller off");
   
  } else if (state == '8') {
    analogWrite(enA, 254);
    Serial.println("Propeller at speed 254");
   
  } else if (state == '9') {
    analogWrite(enA, 255);
    Serial.println("Propeller power on");
   
  }
} 
