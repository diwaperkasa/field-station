#include <Wire.h>
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

void Utils::setDatetime(unsigned int year, unsigned int month, unsigned int day, unsigned int hour, unsigned int minute, unsigned int second)
{
    DS3231 DS3231;

    DS3231.setClockMode(false);
    DS3231.setYear(year);
    DS3231.setMonth(month);
    DS3231.setDate(day);
    DS3231.setHour(hour);
    DS3231.setMinute(minute);
    DS3231.setSecond(second);
}

void Utils::setLedStatus(bool status)
{
    digitalWrite(PIN_LED_NOTOFICATION, status); 
}
