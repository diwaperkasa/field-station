#pragma once

#include <Arduino.h>

class SensorData
{
public:
	static float PRES;	  // Pressure in millibars
	static float TEMP;	  // Temperature in C
	static float DEPTH;	  // Depth in meter
	static float ALTITUDE; // Above mean sea level in meter
	static float WEIGHT;	  // weight in Kg
};
