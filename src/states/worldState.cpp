#include "states/worldState.h"

WorldState::WorldState(LineSensor* linesensors[], IrSensor* irsensors[]) {
    lnsn = linesensors;
    irsn = irsensors;
}

Edge WorldState::isNearEdge() {
    if ((lnsn[0]->getValue() < 200) && (lnsn[1]->getValue() < 200)) {
        return FRONT;
    } else if (lnsn[0]->getValue() < 200) {
        return LEFT;
    } else if (lnsn[1]->getValue() < 200) {
        return RIGHT;
    } else {
        return SAFE;
    }
}

Edge WorldState::enemyPos() {
    if (irsn[1]->getValue() && irsn[2]->getValue()) {
        return FRONT;
    }
    else if (irsn[0]->getValue()) {
        return LEFT;
    }
    else if (irsn[1]->getValue()) {
        return SLIGHT_RIGHT;
    }
    else if (irsn[2]->getValue()) {
        return SLIGHT_LEFT;
    }
    else if (irsn[3]->getValue()) {
        return RIGHT;
    }
    else {
        return SAFE;
    }
}
