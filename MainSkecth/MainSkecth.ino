#include "mHX711.h"
#include "mMS5837.h"
#include "mSdCard.h""

mHX711 mHX711;
mMS5837 mMS5837;
mSdCard mSdCard;

void setup() {
    Serial.begin(115200);
    
    mSdCard.init();
    mHX711.init();
    mMS5837.init();
}

void loop() {
    mHX711.run();
    mMS5837.run();
    mSdCard.run();

    delay(1);
}
