#include "FuelSensor.h"
#include "config.h"
#include <driver/adc.h>

void FuelSensor::begin() {
    analogReadResolution(12);
    pinMode(FUEL_ADC_PIN, INPUT);
}

uint8_t FuelSensor::readFuelLevel() {
    int raw = analogRead(FUEL_ADC_PIN);
    float voltage = raw * (3.3 / 4095.0);
    float clamped = constrain((voltage - FUEL_VOLTAGE_MIN) / (FUEL_VOLTAGE_MAX - FUEL_VOLTAGE_MIN), 0.0, 1.0);
    return static_cast<uint8_t>(clamped * 100.0);
}
