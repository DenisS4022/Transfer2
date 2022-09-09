#pragma once
#include <Arduino.h>

class ADS
{
    public:
        int readADS();
        bool isTimer(unsigned long startTime, unsigned long period);
};