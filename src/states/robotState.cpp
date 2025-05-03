// chooses an algorithm. class you call at the beginning to determine which algortihm to run

#include "states/robotState.h"

RobotState::RobotState() {
}

RobotState::RobotState(WorldState* worldStateParameter, StayOn* stayOnParameter, Attack* attackParameter, RobotAction* robotActionParameter) {
    worldState = worldStateParameter;
    stayOn = stayOnParameter;
    attack = attackParameter;
    robotAction = robotActionParameter;
}

void RobotState::win() {
    Edge enemyStatus = worldState->enemyPos();
    Edge edgeStatus = worldState->isNearEdge();

    if (enemyStatus != SAFE && edgeStatus == SAFE) {
        attack->performAttack();
    } else {
        stayOn->runAlgorithm();
    }
}

