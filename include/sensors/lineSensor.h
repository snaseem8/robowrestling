#ifndef LINESENSOR_H
#define LINESENSOR_H

class LineSensor {
private:
    int value;
public:
    LineSensor();
    LineSensor(int sensorValue);
    int getValue();
    void setValue(int sensorValue);
};

#endif
