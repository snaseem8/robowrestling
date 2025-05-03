#include "action/robotAction.h"

RobotAction::RobotAction(MotorDriver* leftMotorParameter, MotorDriver* rightMotorParameter) {
    leftMotor = leftMotorParameter;
    rightMotor = rightMotorParameter;
}

void RobotAction::turnLeft() {
    leftMotor->setDir(false);
    rightMotor->setDir(true);
    rightMotor->setSpeed(100);
    leftMotor->setSpeed(100);
}

void RobotAction::turnRight() {
    leftMotor->setDir(true);
    rightMotor->setDir(false);
    leftMotor->setSpeed(100);
    rightMotor->setSpeed(100);
}

void RobotAction::go() {
    leftMotor->setDir(1);
    rightMotor->setDir(1);
    leftMotor->setSpeed(80);
    rightMotor->setSpeed(80);
}

void RobotAction::GOGOGO() {
    leftMotor->setDir(true);
    rightMotor->setDir(true);
    leftMotor->setSpeed(200);
    rightMotor->setSpeed(200);
}

void RobotAction::reverse() {
    leftMotor->setDir(false);
    rightMotor->setDir(false);
    leftMotor->setSpeed(90);
    rightMotor->setSpeed(90);
}

void RobotAction::reverseLeft() {
    leftMotor->setDir(true);
    rightMotor->setDir(false);
    leftMotor->setSpeed(30);
}
