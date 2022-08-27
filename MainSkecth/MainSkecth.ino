#include "mHX711.h"
#include "mMS5837.h"
#include "mSdCard.h""
#include "Setting.h""

mHX711 mHX711;
mMS5837 mMS5837;
mSdCard mSdCard;

void setup() {
    Serial.begin(SERIAL_BAUDRATE);
    
    mSdCard.init();
    mHX711.init();
    mMS5837.init();
}

void loop() {
    mHX711.run();
    mMS5837.run();
    mSdCard.run();

    delay(1000);
}
