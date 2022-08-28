#ifndef mMS5837_h
#define mMS5837_h

#include <Wire.h>
#include "MS5837.h"

class mMS5837
{
private:
    /* data */
    bool initStatus = true;
    MS5837 MS5837Sensor;
public:
    mMS5837(/* args */);
    virtual ~mMS5837();

    void init();
    void run();
};

#endif
