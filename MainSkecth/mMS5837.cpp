#include <Wire.h>
#include "SensorData.h"
#include "MS5837.h"
#include "mMS5837.h"
#include "Utils.h"

MS5837 MS5837Sensor;

float SensorData::PRES = 0;
float SensorData::TEMP = 0;
float SensorData::DEPTH = 0;
float SensorData::ALTITUDE = 0;

mMS5837::mMS5837(/* args */)
{
}

mMS5837::~mMS5837()
{
}

void mMS5837::init()
{
    Utils Utility;

    Wire.begin();

    if (!MS5837Sensor.init()) {
        Serial.print(F("log:Bar20 Initialize failed;"));
        initStatus = false;
        Utility.setLedStatus(true);
    }
}

void mMS5837::run()
{
    if (!initStatus) return;

    MS5837Sensor.read();

    SensorData::PRES = MS5837Sensor.pressure();
    SensorData::TEMP = MS5837Sensor.temperature();
    SensorData::DEPTH = MS5837Sensor.depth();
    SensorData::ALTITUDE = MS5837Sensor.altitude();
}
