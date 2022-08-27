#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "mSdCard.h"
#include "Setting.h"
#include "SensorData.h"
#include "Utils.h""

Utils Utility;

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

    SdVolume volume;
    unsigned int volumesize = volume.blocksPerCluster();
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
    sprintf(filename, "%i-%i-%i.csv", now.day(), now.month(), now.year());

    Serial.print("log:filename ");
    Serial.print(filename);
    Serial.println(";");
    
    File file = SD.open(filename, FILE_WRITE);

    Serial.print("log:file status ");
    Serial.print(file);
    Serial.println(";");

    if (!SD.exists(filename) && file) {
      // set header csv file
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

    if (file) {
        char date[20];
        sprintf(date, "%i-%i-%i %i:%i:%i", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());

        Serial.print("log:datetime ");
        Serial.print(date);
        Serial.println(";");
        
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
