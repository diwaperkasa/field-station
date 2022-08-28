#ifndef mHX711_h
#define mHX711_h

#include <Wire.h>
#include "HX711.h"
#include "SensorData.h"
#include "Setting.h"

class mHX711
{
private:
    /* data */
    bool initStatus;
    HX711 HX711Sensor;
public:
    mHX711(/* args */);
    virtual ~mHX711();

    void init();
    void run();
};

#endif
