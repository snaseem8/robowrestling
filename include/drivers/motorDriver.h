#ifndef MOTOR_DRIVER_H_
#define MOTOR_DRIVER_H_

class MotorDriver {
private:
    int dir;
    unsigned int speed;
public:
    MotorDriver();
    MotorDriver(int init_speed);
    MotorDriver(int init_speed, int init_dir);
    int getDir();
    void setDir(int);
    int getSpeed();
    void setSpeed(int);
};

#endif
