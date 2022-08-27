#include <Arduino.h>
#include <SPI.h>
#include <SD.h>
#include "mSdCard.h"
#include "Setting.h"
#include "SensorData.h"
#include "Utils.h""
#include "DS3231.h"

Utils Utility;

mSdCard::mSdCard(/* args */)
{
}

mSdCard::~mSdCard()
{
}

void mSdCard::init()
{
    Utility.setDatetime(2022, 8, 27, 15, 27);
    
    if (!SD.begin(SDCARD_CS_PIN)) {
        initStatus = false;
        Serial.print(F("log:Memory Card not detected;"));
        Utility.setLedStatus(true);
        return;
    }
}

void mSdCard::run()
{
    if (!initStatus) return;

    DateTime now = Utility.getDateTime();
    char filename[15];
    sprintf(filename, "%02d%02d%d.csv", now.day(), now.month(), now.year());
    File file = SD.open(filename, FILE_WRITE);

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
        sprintf(date, "%d-%02d-%02d %02d:%02d:%02d", now.year(), now.month(), now.day(), now.hour(), now.minute(), now.second());

        Serial.print(F("datetime:"));
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

    file.close();

    Utility.blinkLed();
}
