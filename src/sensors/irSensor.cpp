#include "sensors/irSensor.h"

IrSensor::IrSensor() {
    value = 0;
}

IrSensor::IrSensor(int sensorValue) {
    value = sensorValue;
}

int IrSensor::getValue() {
    return value;
}

void IrSensor::setValue(int sensorValue) {
    value = sensorValue;
}
