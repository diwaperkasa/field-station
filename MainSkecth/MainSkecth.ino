#include <Arduino.h>
#include <Wire.h>
#include "mHX711.h"
#include "mMS5837.h"
#include "mSdCard.h"
#include "Setting.h"
#include "Utils.h"

mHX711 mHX711;
mMS5837 mMS5837;
mSdCard mSdCard;
Utils Utility;

void setup() {
  Serial.begin(SERIAL_BAUDRATE);
  Serial.println(F("log:device restart now;"));

  pinMode(RTC_ALARM_PIN, INPUT_PULLUP);
  Utility.init();
  Utility.setLedStatus(false);
  Utility.setRelayStatus(true);
  Utility.blinkLed();

  mSdCard.init();
  mHX711.init();
  mMS5837.init();
}

void loop() {
  mHX711.run();
  mMS5837.run();
  mSdCard.run();
  // interrupt pin
  attachInterrupt(digitalPinToInterrupt(RTC_ALARM_PIN), wakeUp, FALLING);
  // turn off power sensor
  Utility.setRelayStatus(false);
  // set power down mode, with alarm set in second
  Utility.sleep(ALARM_TO_SECOND);
  // disable external pin interrupt on wake up pin.
  detachInterrupt(digitalPinToInterrupt(RTC_ALARM_PIN)); 
}

// handler for the pin interrupt.
void wakeUp() {
  // turn on power sensor
  Utility.setRelayStatus(true);
  Utility.blinkLed();
}
