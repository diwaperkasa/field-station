#include <Wire.h>
#include "SensorData.h"
#include "MS5837.h"
#include "mMS5837.h"

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
    Wire.begin();

    if (!MS5837Sensor.init())
    {
        Serial.print(F("log:"));
        Serial.print(F("Bar20 Initialize failed"));
        Serial.println(';');

        initStatus = false;
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

    Serial.print(F("pressure:"));
    Serial.print(SensorData::PRES);
    Serial.print(';');

    Serial.print(F("temp:"));
    Serial.print(SensorData::TEMP);
    Serial.print(';');

    Serial.print(F("depth:"));
    Serial.print(SensorData::DEPTH);
    Serial.print(';');

    Serial.print(F("altitude:"));
    Serial.print(SensorData::ALTITUDE);
    Serial.println(';');
}
