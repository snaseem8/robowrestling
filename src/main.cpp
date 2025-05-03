 #include <Arduino.h>

 // Includes
 #include "drivers/motorDriver.h"
 #include "states/robotState.h"
 #include "states/worldState.h"
 #include "action/robotAction.h"
 #include "sensors/lineSensor.h"
 #include "sensors/irSensor.h"
 #include "strategies/stayOn.h"
 #include "strategies/attack.h"
 
 // Pinouts
 #define Lside 12
 #define LSensor 8
 #define Rside 2
 #define RSensor 4
 #define StartMod 10
 #define Rpos 13
 #define Rneg 11
 #define Lpos A5
 #define Lneg 6
 #define PWMRight 5
 #define PWMLeft 3
 #define switch1 A7
 #define switch2 A6
 #define lineLeft A0
 #define lineRight A1
 
 // Objects
 MotorDriver* leftMotorDriver;
 MotorDriver* rightMotorDriver;
 RobotAction* robotAction;
 WorldState* worldState;
 LineSensor* lineSensors[2];
 IrSensor* irSensors[4];
 StayOn* stayOn;
 Attack* attack;
 RobotState* robotState;
 
 void pollSensors();
 void updateMotors();
 
 void setup() {
     pinMode(Rpos, OUTPUT);
     pinMode(Rneg, OUTPUT);
     pinMode(Lpos, OUTPUT);
     pinMode(Lneg, OUTPUT);
     pinMode(Lside, INPUT);
     pinMode(LSensor, INPUT);
     pinMode(RSensor, INPUT);
     pinMode(Rside, INPUT);
     pinMode(lineLeft, INPUT); 
     pinMode(lineRight, INPUT);
     pinMode(StartMod, INPUT);
     pinMode(switch1, INPUT);
     pinMode(switch2, INPUT);
 
     Serial.begin(9600);
 
     leftMotorDriver = new MotorDriver();
     rightMotorDriver = new MotorDriver();
 
     lineSensors[0] = new LineSensor(0);
     lineSensors[1] = new LineSensor(0);
 
     irSensors[0] = new IrSensor(0);
     irSensors[1] = new IrSensor(0);
     irSensors[2] = new IrSensor(0);
     irSensors[3] = new IrSensor(0);
 
     robotAction = new RobotAction(leftMotorDriver, rightMotorDriver);
     worldState = new WorldState(lineSensors, irSensors);
     stayOn = new StayOn(robotAction, worldState);
     attack = new Attack(robotAction, worldState);
     robotState = new RobotState(worldState, stayOn, attack, robotAction);
 }
 
 void loop() {
     pollSensors();
     robotState->win();
     updateMotors();
 }
 
 void updateMotors() {
     int leftDir = leftMotorDriver->getDir();
     int leftSpeed = leftMotorDriver->getSpeed();
 
     if (leftDir == 1) {
         analogWrite(Lpos, 250);
         analogWrite(Lneg, 0);
     } else {
         analogWrite(Lpos, 0);
         analogWrite(Lneg, 250);
     }
 
     int rightDir = rightMotorDriver->getDir();
     int rightSpeed = rightMotorDriver->getSpeed();
 
     if (rightDir == 1) {
         analogWrite(Rpos, 250);
         analogWrite(Rneg, 0);
     } else {
         analogWrite(Rpos, 0);
         analogWrite(Rneg, 250);
     }
 
     analogWrite(PWMLeft, leftSpeed);
     analogWrite(PWMRight, rightSpeed);
 }
 
 void pollSensors() {
     lineSensors[0]->setValue(analogRead(lineLeft));
     lineSensors[1]->setValue(analogRead(lineRight));
 
     irSensors[0]->setValue(digitalRead(Lside));
     irSensors[1]->setValue(digitalRead(LSensor));
     irSensors[2]->setValue(digitalRead(RSensor));
     irSensors[3]->setValue(digitalRead(Rside));
 }
