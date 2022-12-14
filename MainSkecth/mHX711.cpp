#include <Arduino.h>
#include "SensorData.h"
#include "mHX711.h"
#include "Setting.h"

float SensorData::WEIGHT = 0;

mHX711::mHX711(/* args */)
{
}

mHX711::~mHX711()
{
}

void mHX711::init()
{
    HX711Sensor.begin(HX711_LOADCELL_DOUT_PIN, HX711_LOADCELL_SCK_PIN);
    HX711Sensor.set_scale(HX711_LOADCELL_DIVIDER);
    HX711Sensor.set_offset(HX711_LOADCELL_OFFSET);
}

void mHX711::run()
{
    SensorData::WEIGHT = HX711Sensor.get_units(HX711_AVERAGE_SAMPLE_DATA);
}
