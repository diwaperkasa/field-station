#include "Utils.h"
#include "DS3231.h"
#include "Setting.h"

Utils::Utils(/* args */)
{
}

Utils::~Utils()
{
}

DateTime Utils::getDateTime()
{
    RTClib RTC;
    DateTime now = RTC.now();

    return now;
}

void Utils::setTime()
{
    
}

void Utils::setLedStatus(bool status)
{
    digitalWrite(PIN_LED_NOTOFICATION, status); 
}
