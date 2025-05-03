#ifndef IRSENSOR_H
#define IRSENSOR_H

class IrSensor {
private:
    int value;
public:
    IrSensor();
    IrSensor(int sensorValue);
    int getValue();
    void setValue(int sensorValue);
};

#endif
