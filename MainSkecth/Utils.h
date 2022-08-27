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
    void setDatetime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour = 0, unsigned int minute = 0, unsigned int second = 0);
    void setLedStatus(bool status);
};

#endif
