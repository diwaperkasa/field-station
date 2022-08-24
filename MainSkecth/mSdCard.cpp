#include <SPI.h>
#include <SD.h>
#include "mSdCard.h"
#include "Setting.h"
#include "SensorData.h"

File file;
Sd2Card card;
SdVolume volume;
SdFile root;

unsigned int volumesize = 0;

mSdCard::mSdCard(/* args */)
{
}

mSdCard::~mSdCard()
{
}

void mSdCard::init()
{
    if (!SD.begin(10)) {
        initStatus = false;
        
        Serial.print(F("log:"));
        Serial.print(F("Memory Card not detected"));
        Serial.println(';');
    } else {
        volumesize = volume.blocksPerCluster();
        volumesize *= volume.clusterCount();
        volumesize /= 1024;

        Serial.print(F("log:"));
        Serial.print(F("Memory Card volume size "));
        Serial.print(volumesize);
        Serial.print(F(" (Mbytes)"));
        Serial.println(';');
    }
}

void mSdCard::run()
{
    if (!initStatus) return;

    file = SD.open("test.csv", FILE_WRITE);

    if (file) {
        file.print(SensorData::PRES);
        file.print(",");
        file.print(SensorData::TEMP);
        file.print(",");
        file.print(SensorData::DEPTH);
        file.print(",");
        file.print(SensorData::ALTITUDE);
        file.print(",");
        file.println(SensorData::WEIGHT);
    }
}
