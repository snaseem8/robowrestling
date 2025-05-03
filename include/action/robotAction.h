#ifndef ROBOT_ACTION_H_
#define ROBOT_ACTION_H_

#include "drivers/motorDriver.h"

class RobotAction {
private:
    MotorDriver* leftMotor;
    MotorDriver* rightMotor;
public:
    RobotAction(MotorDriver* leftMotorParameter, MotorDriver* rightMotorParameter);
    void turnLeft();
    void turnRight();
    void go();
    void GOGOGO();
    void reverse();
    void reverseLeft();
    void reverseRight();
};

#endif
