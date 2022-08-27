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

void Utils::setDatetime(byte year, byte month, byte day, byte hour, byte minute, byte second)
{
    DS3231 DS3231lib;

    DS3231lib.setClockMode(false);
    DS3231lib.setYear(year);
    DS3231lib.setMonth(month);
    DS3231lib.setDate(day);
    DS3231lib.setHour(hour);
    DS3231lib.setMinute(minute);
    DS3231lib.setSecond(second);
}

void Utils::setLedStatus(bool status)
{
    digitalWrite(PIN_LED_NOTOFICATION, status); 
}

void Utils::blinkLed()
{
    Utils::setLedStatus(true);
    delay(100);
    Utils::setLedStatus(false);
}