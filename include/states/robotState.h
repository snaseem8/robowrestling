#ifndef ROBOT_STATE_H_
#define ROBOT_STATE_H_

#include "states/worldState.h"
#include "strategies/stayOn.h"
#include "strategies/attack.h"
#include "action/robotAction.h"

class RobotState {
private:
    WorldState* worldState;
    StayOn* stayOn;
    Attack* attack;
    RobotAction* robotAction;
public:
    RobotState();
    RobotState(WorldState* worldStateParameter, StayOn* stayOnParameter, Attack* attackParameter, RobotAction* robotActionParameter);
    void win();
};

#endif
