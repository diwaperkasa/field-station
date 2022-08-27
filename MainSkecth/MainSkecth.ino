#include "mHX711.h"
#include "mMS5837.h"
#include "mSdCard.h"
#include "Setting.h"
#include "Utils.h"

mHX711 mHX711;
mMS5837 mMS5837;
mSdCard mSdCard;

void setup() {
    Utils Utility;
    
    Serial.begin(SERIAL_BAUDRATE);
    Serial.println(F("log:device restart now;"));
    Utility.setLedStatus(false);
    mSdCard.init();
    mHX711.init();
    mMS5837.init();
}

void loop() {
    mHX711.run();
    mMS5837.run();
    mSdCard.run();

    //delay(1000);
}
