#ifndef ATTACK_H_
#define ATTACK_H_

#include "action/robotAction.h"
#include "states/worldState.h"

class Attack {
private:
    RobotAction* robotAction;
    WorldState* worldState;
public:
    Attack(RobotAction* robotActionParameter, WorldState* worldStateParameter);
    void performAttack();
};

#endif
