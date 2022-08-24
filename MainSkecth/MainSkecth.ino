#include "mHX711.h"
#include "mMS5837.h"

mHX711 mHX711;
mMS5837 mMS5837;

void setup() {
    mHX711.init();
    mMS5837.init();
}

void loop() {
    mHX711.readData();
    mMS5837.readData();
}
