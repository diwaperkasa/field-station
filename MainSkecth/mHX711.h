#ifndef mHX711_h
#define mHX711_h

#include <Wire.h>
#include "HX711.h"
#include "SensorData.h"

class mHX711
{
private:
    /* data */
    bool initStatus;
public:
    mHX711(/* args */);
    virtual ~mHX711();

    void init();
    void run();
};

#endif
