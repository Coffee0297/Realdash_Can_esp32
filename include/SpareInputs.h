#ifndef SPARE_INPUTS_H
#define SPARE_INPUTS_H
#include <Arduino.h>

class SpareInputs {
public:
    void begin();
    uint8_t readInputs();
};

#endif
