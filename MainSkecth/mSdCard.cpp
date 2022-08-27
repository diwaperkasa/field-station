#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "mSdCard.h"
#include "Setting.h"
#include "SensorData.h"
#include "Utils.h""

Sd2Card card;
SdVolume volume;
SdFile root;
Utils Utility;

unsigned int volumesize = 0;

mSdCard::mSdCard(/* args */)
{
}

mSdCard::~mSdCard()
{
}

void mSdCard::init()
{
    Utility.setLedStatus(false);
    
    if (!SD.begin(SDCARD_CS_PIN)) {
        initStatus = false;
        
        Serial.print(F("log:"));
        Serial.print(F("Memory Card not detected"));
        Serial.println(';');

        Utility.setLedStatus(true);

        return;
    }

    volumesize = volume.blocksPerCluster();
    volumesize *= volume.clusterCount();
    volumesize /= 1024;

    Serial.print(F("log:"));
    Serial.print(F("Memory Card volume size "));
    Serial.print(volumesize);
    Serial.print(F(" (Mbytes)"));
    Serial.println(';');
}

void mSdCard::run()
{
    if (!initStatus) return;

    DateTime now = Utility.getDateTime();
    char filename[12];
    sprintf(filename, "%02d-%02d-%d.csv", now.day(), now.month(), now.year());
    
    File file = SD.open(filename, FILE_WRITE);

    if (SD.exists(filename)) {
      // set header csl file
      if (file) {
        file.print("date");
        file.print(",");
        file.print("pressure");
        file.print(",");
        file.print("temp");
        file.print(",");
        file.print("depth");
        file.print(",");
        file.print("altitude");
        file.print(",");
        file.println("weight");
      }
    }

    if (file) {
        char date[20];
        sprintf(date, "%02d-%02d-%d %02d:%02d:%02d", now.day(), now.month(), now.year(), now.hour(), now.minute(), now.second());
        
        file.print(date);
        file.print(",");
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
