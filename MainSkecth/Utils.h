#ifndef Utils_h
#define Utils_h

#include <Wire.h>
#include "DS3231.h"
#include "LowPower.h"

class Utils
{
private:
    /* data */
    DS3231 rtc;
public:
    Utils(/* args */);
    ~Utils();

    DateTime getDateTime();
    void setDatetime(DateTime dt);
    void setLedStatus(bool status);
    void blinkLed();
    void sleep(unsigned int interval);
};

#endif
