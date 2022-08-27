#ifndef Utils_h
#define Utils_h

#include "DS3231.h"

class Utils
{
private:
    /* data */
public:
    Utils(/* args */);
    ~Utils();

    DateTime getDateTime();
    void setDatetime(byte year, byte month, byte day, byte hour = 0, byte minute = 0, byte second = 0);
    void setLedStatus(bool status);
    void blinkLed();
};

#endif
