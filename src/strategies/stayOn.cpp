#include "strategies/stayOn.h"

StayOn::StayOn(RobotAction* robotActionParameter, WorldState* worldStateParameter) {
    robotAction = robotActionParameter;
    worldState = worldStateParameter;
}

void StayOn::runAlgorithm() {
    Edge edge_pos = worldState->isNearEdge(); 
    if (edge_pos == FRONT) {
        robotAction->reverse();
    } else if (edge_pos == LEFT) {
        robotAction->reverseLeft();
    } else if (edge_pos == RIGHT) {
        robotAction->reverseRight();
    } else {
        robotAction->go();
    }
}
