#ifndef WORLD_STATE_H_
#define WORLD_STATE_H_

#include "sensors/lineSensor.h"
#include "sensors/irSensor.h"

enum Edge {
    LEFT,
    SLIGHT_LEFT,
    RIGHT,
    SLIGHT_RIGHT,
    FRONT,
    BACK,
    CLOSE_FRONT,
    SAFE
};

class WorldState {
private:
    LineSensor** lnsn;
    IrSensor** irsn;
public:
    WorldState(LineSensor*[], IrSensor*[]);
    Edge isNearEdge();
    Edge enemyPos();
};

#endif
