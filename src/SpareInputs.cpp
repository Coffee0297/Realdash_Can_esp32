#include "SpareInputs.h"
#include "config.h"
#include <Arduino.h>

void SpareInputs::begin() {
    pinMode(SPARE_INPUT_1, INPUT_PULLUP);
    pinMode(SPARE_INPUT_2, INPUT_PULLUP);
    pinMode(SPARE_INPUT_3, INPUT_PULLUP);
    pinMode(SPARE_INPUT_4, INPUT_PULLUP);
    pinMode(SPARE_INPUT_5, INPUT_PULLUP);
    pinMode(SPARE_INPUT_6, INPUT_PULLUP);
}

uint8_t SpareInputs::readInputs() {
    uint8_t status = 0;
    status |= (!digitalRead(SPARE_INPUT_1)) << 0;
    status |= (!digitalRead(SPARE_INPUT_2)) << 1;
    status |= (!digitalRead(SPARE_INPUT_3)) << 2;
    status |= (!digitalRead(SPARE_INPUT_4)) << 3;
    status |= (!digitalRead(SPARE_INPUT_5)) << 4;
    status |= (!digitalRead(SPARE_INPUT_6)) << 5;
    return status;
}
