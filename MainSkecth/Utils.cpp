#include "Utils.h"
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

void Utils::init()
{
  pinMode(PIN_LED_NOTIFICATION, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);
}

void Utils::setDatetime(DateTime dt)
{
  rtc.setEpoch(dt.unixtime());
}

void Utils::setLedStatus(bool status)
{
  digitalWrite(PIN_LED_NOTIFICATION, status ? HIGH : LOW);
}

void Utils::setRelayStatus(bool status)
{
  if (RELAY_INVERTED_MODE) {
    status = !status;
  }
  
  digitalWrite(RELAY_PIN, status ? HIGH : LOW);
}

void Utils::blinkLed()
{
  Utils::setLedStatus(true);
  delay(100);
  Utils::setLedStatus(false);
}

void Utils::sleep(unsigned int interval)
{
  DateTime now = Utils::getDateTime();
  DateTime nextAlarm = DateTime(now.unixtime() + interval);
  rtc.turnOffAlarm(1);
  rtc.turnOffAlarm(2);
  rtc.setA1Time(nextAlarm.day(), nextAlarm.hour(), nextAlarm.minute(), nextAlarm.second(), 8, false, false, false);
  delay(100); // wait for a moment for everything to complete
  LowPower.powerDown(SLEEP_FOREVER, ADC_OFF, BOD_OFF); // power down everything until the alarm fires
}
