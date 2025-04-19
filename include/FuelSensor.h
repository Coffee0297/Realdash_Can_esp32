#ifndef FUEL_SENSOR_H
#define FUEL_SENSOR_H
#include "driver/adc.h"
#include <Arduino.h>

class FuelSensor {
public:
    void begin();
    uint8_t readFuelLevel();
};

#endif
