#include "strategies/attack.h"

Attack::Attack(RobotAction* robotActionParameter, WorldState* worldStateParameter) {
    robotAction = robotActionParameter;
    worldState = worldStateParameter;
}

void Attack::performAttack() {
    Edge enemyPosition = worldState->enemyPos();

    switch (enemyPosition) {
        case FRONT:
            robotAction->go();
            break;
        case LEFT:
            robotAction->turnLeft();
            break;
        case RIGHT:
            robotAction->turnRight();
            break;
        case SLIGHT_LEFT:
            robotAction->turnLeft();
            break;
        case SLIGHT_RIGHT:
            robotAction->turnRight();
            break;
        case CLOSE_FRONT:
            robotAction->GOGOGO();
            break;
        case SAFE:
            robotAction->go();
            break;
        default:
            robotAction->go();
            break;
    }
}
