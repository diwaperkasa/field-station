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
    void setTime();
    void setLedStatus(bool status);
};

#endif
