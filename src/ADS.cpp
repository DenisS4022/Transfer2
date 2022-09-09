#include <ADS.h>
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 _ADS1x15_1_instance(0x48);
int _ADS1x15_1_Output_1 = 0;
bool _ADS1x15_1_isNeedRequest_1 = 0;
unsigned long _ADS1x15_1_StartTime_1 = 0UL;

int ADS::readADS()
{
    if((_ADS1x15_1_StartTime_1 == 0) || (isTimer(_ADS1x15_1_StartTime_1 , 1000)))
    {
        _ADS1x15_1_StartTime_1 = millis();
        _ADS1x15_1_isNeedRequest_1 = 1;
    }
    if(_ADS1x15_1_isNeedRequest_1) 
    {
        _ADS1x15_1_isNeedRequest_1 = 0;
        _ADS1x15_1_Output_1 = _ADS1x15_1_instance.readADC_SingleEnded(0);
    }
    return _ADS1x15_1_Output_1;
}

bool ADS::isTimer(unsigned long startTime, unsigned long period)
{
    unsigned long currentTime;
    currentTime = millis();
    if (currentTime>= startTime) 
    {
        return (currentTime>=(startTime + period));
    }
     else 
    {
        return (currentTime >=(4294967295-startTime+period));
    } 
}