#include <Timer.h>
#include <TimeLib.h>
#include <WiFiUdp.h>
WiFiUDP _ntpUdpServer;
const int timeZone = 3;

const int NTP_PACKET_SIZE = 48; // NTP time is in the first 48 bytes of message
byte packetBuffer[NTP_PACKET_SIZE]; //buffer to hold incoming & outgoing packets

void Timer::setRealTime(String Time, String Data)
{
    int hours = 0;
    int minutes = 0;
    int seconds = 0;

    int day = 0;
    int month = 0;
    int years = 0;
    hours = Time.substring(0, 2).toInt();
    minutes = Time.substring(3, 5).toInt();
    seconds = Time.substring(6, 7).toInt();

    day = Data.substring(8).toInt();
    month = Data.substring(5,8).toInt();
    years = Data.substring(0,4).toInt();
    setTime(hours, minutes, seconds, day, month, years);
}