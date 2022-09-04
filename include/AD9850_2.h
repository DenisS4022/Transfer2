#pragma once
#include <Arduino.h>

class AD9850
{
    public:
        void setup();
        void setfreq(float frequency, byte phase);
};