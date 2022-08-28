#ifndef mSdCard_h
#define mSdCard_h

#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "SensorData.h"
#include "Utils.h"

class mSdCard
{
private:
    /* data */
    bool initStatus = true;
    Utils Utility;
public:
    mSdCard(/* args */);
    ~mSdCard();

    void init();
    void run();
};

#endif
