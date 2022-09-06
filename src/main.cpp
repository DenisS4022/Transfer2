#include <Arduino.h>
#include <Menu.h>

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <NTPClient.h>
#include <TimeLib.h>
#include <Timer.h>

#include <EncButton.h>
#include <string>
#include <iostream>
// #include <Adafruit_MCP23X17.h>
#include <MQTT.h>

#include <MCP23017_Buttons.h>
#include <Preferences.h>

#include <Wire.h>
#include <Adafruit_ADS1X15.h>
Adafruit_ADS1115 ads;

Preferences preferences;

float frequency_memory = 0;
float PWM_memory = 0;
float frequency_modulation_memory = 0;
float PWM_modulation_memory = 0;

// Adafruit_MCP23X17 mcp;
// #include <Keyboard.h>

EncButton<EB_TICK, 32, 33> enc1;
EncButton<EB_TICK, 14, 4> enc2;

const char *ssid = "L132.4GHz";
const char *password = "Des1229des";

Buttons btn_0 = Buttons(0);
Buttons btn_1 = Buttons(1);
Buttons btn_2 = Buttons(2);
Buttons btn_3 = Buttons(3);
Buttons btn_4 = Buttons(4);
Buttons btn_5 = Buttons(5);
Buttons btn_6 = Buttons(6);
Buttons btn_7 = Buttons(7);
Buttons btn_8 = Buttons(8);
Buttons btn_9 = Buttons(9);
Buttons btn_10 = Buttons(10);
Buttons btn_11 = Buttons(11);
Buttons btn_12 = Buttons(12);
Buttons btn_13 = Buttons(13);
Buttons btn_14 = Buttons(14);
Buttons btn_15 = Buttons(15);
Buttons btn_16 = Buttons(16);
IPAddress NTP_IP;

WiFiUDP ntpUDP;
NTPClient timeClient(ntpUDP);

String formattedDate;

bool btnflag = false;
bool SubMenuDraw = false;
bool MainMenuDraw = true;
bool SubMenuflag = false;
bool MainMenuflag = false;
extern bool set_flag;
extern int last_state;
extern bool full_clear;

int SubSettings = 1;
int MenuLevel = 0;
int pageCounter = 1;

float frequency = 0;
float Oldfrequency;

float PWM = 0;
float OldPWM;

float frequencySteps[] = {0.1f, 1.0f, 10.0f, 100.0f, 1000.0f, 10000.0f, 100000.0f};
int i = 3;
float frequencyStep = frequencySteps[i];
float OldFrequencyStep;

float Current = 1.0;
float OldCurrent;

float MemoryFrequency = 0;
float OldMemoryFrequency;

float DutyTime = 0;
float PrintedDutyTime = 0;
float OldDutyTime;
String TimeUnits;

float StepDutyTime = 0;
float OldStepDutyTime;
float PrintedStepDutyTime = 0;
String StepUnits;

float period = 0;

String IP;
String OldIP;

String Time = "15:50:59";
String OldTime;

String Data = "19.08.2022";
String OldData;

String MQTT = "MQTT - N/A";
String OldMQTT;

// Menu menu;
Timer clocks;
// Keyboard keyb;

int adc;

void setup()
{
  Serial.begin(115200);
  Serial.println("1");

  pinMode(34, INPUT);

  preferences.begin("memory", false);
  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  WiFi.hostByName("ua.pool.ntp.org", NTP_IP);
  ArduinoOTA.setHostname("a[D]rian");
  ArduinoOTA.begin();

  esp.MQTT_Setup();
  timeClient.begin();
  timeClient.setTimeOffset(10800);
  mcp.begin_I2C(0x20);
  // mcp.begin_I2C();
  // mcp.pinMode(1, INPUT);
  // mcp.pinMode(2, INPUT);

  while (!timeClient.update())
  {
    timeClient.forceUpdate();
  }
  formattedDate = timeClient.getFormattedDate();
  int splitT = formattedDate.indexOf("T");
  Data = formattedDate.substring(0, splitT);
  Time = formattedDate.substring(splitT + 1, formattedDate.length() - 1);
  clocks.setRealTime(Time, Data);

  MemoryFrequency = preferences.getFloat("freq_memory", 0);
  menu.start();
  menu.cleanDisplay();
  menu.DrawIP(IP);
  menu.DrawFrequency(frequency);
  menu.DrawPWM(PWM);
  menu.DrawFrequencyStep(frequencyStep);
  menu.DrawCurrent(Current);
  menu.DrawDutyTime(DutyTime, TimeUnits);
  menu.DrawStepDutyTime(StepDutyTime, StepUnits);
  menu.DrawButton(250, 280, 210, 30, 3, 0xFF20, (String)MemoryFrequency);
  menu.DrawButton(30, 280, 210, 30, 3, 0xFF20, MQTT);
  menu.DrawData(day(), month(), year());
  menu.DrawTime(hour(), minute(), second());
  preferences.end();

  // Модуль 16-битного АЦП ADS1115
  // ВОЗМОЖНЫЕ ВАРИАНТЫ УСТАНОВКИ КУ:
  // ads.setGain(GAIN_TWOTHIRDS); | 2/3х | +/-6.144V | 1bit = 0.1875mV    |
  // ads.setGain(GAIN_ONE);       | 1х   | +/-4.096V | 1bit = 0.125mV     |
  // ads.setGain(GAIN_TWO);       | 2х   | +/-2.048V | 1bit = 0.0625mV    |
  // ads.setGain(GAIN_FOUR);      | 4х   | +/-1.024V | 1bit = 0.03125mV   |
  // ads.setGain(GAIN_EIGHT);     | 8х   | +/-0.512V | 1bit = 0.015625mV  |
  // ads.setGain(GAIN_SIXTEEN);   | 16х  | +/-0.256V | 1bit = 0.0078125mV |
  ads.setGain(GAIN_TWOTHIRDS);
  ads.begin();
}

void loop()
{
  enc1.tick();
  enc2.tick();

  // считываем с АЦП ADS1115
  adc = ads.readADC_SingleEnded(0); // (0) - номер канала
  float u = float(adc) * 0.1875 / 1000.0;

  preferences.begin("memory", false);
  ArduinoOTA.handle();

  String RealTime = String(hour()) + ":" + String(minute()) + ":" + String(second());
  String RealData = String(day()) + "-" + String(month()) + "-" + String(year());
  if (MainMenuDraw)
  {
    if (MainMenuflag)
    {
      menu.cleanDisplay();
      menu.DrawIP(IP);
      menu.DrawFrequency(frequency);
      menu.DrawPWM(PWM);
      menu.DrawFrequencyStep(frequencyStep);
      menu.DrawCurrent(Current);
      menu.DrawDutyTime(DutyTime, TimeUnits);
      menu.DrawStepDutyTime(StepDutyTime, StepUnits);
      menu.DrawButton(250, 280, 210, 30, 3, 0xFF20, (String)MemoryFrequency);
      menu.DrawButton(30, 280, 210, 30, 3, 0xFF20, MQTT);
      menu.DrawData(day(), month(), year());
      menu.DrawTime(hour(), minute(), second());
      MainMenuflag = false;
    }
    menu.DrawBitmaps();
    IP = (WiFi.localIP()).toString();
    if (OldIP != IP)
    {
      menu.DrawIP(IP);
      OldIP = IP;
    }

    if (Oldfrequency != frequency)
    {
      menu.DrawFrequency(frequency);
      esp.MQTT_pub("freq", frequency);
      Oldfrequency = frequency;
    }

    if (OldPWM != PWM)
    {
      menu.DrawPWM(PWM);
      esp.MQTT_pub("PWM3", PWM);
      OldPWM = PWM;
    }

    if (OldFrequencyStep != frequencyStep)
    {
      menu.DrawFrequencyStep(frequencyStep);

      OldFrequencyStep = frequencyStep;
    }

    if (OldCurrent != Current)
    {
      menu.DrawCurrent(Current);
      OldCurrent = Current;
    }

    if (OldDutyTime != PrintedDutyTime)
    {
      menu.DrawDutyTime(PrintedDutyTime, TimeUnits);
      OldDutyTime = PrintedDutyTime;
    }

    if (OldStepDutyTime != StepDutyTime)
    {
      menu.DrawStepDutyTime(StepDutyTime, StepUnits);
      OldStepDutyTime = StepDutyTime;
    }

    if (OldMemoryFrequency != MemoryFrequency)
    {
      menu.DrawButton(250, 280, 210, 30, 3, 0xFF20, (String)MemoryFrequency);
      OldMemoryFrequency = MemoryFrequency;
    }

    if (OldMQTT != MQTT)
    {
      menu.DrawButton(30, 280, 210, 30, 3, 0xFF20, MQTT);
      OldMQTT = MQTT;
    }

    if (OldData != RealData)
    {
      menu.DrawData(day(), month(), year());
      OldData = RealData;
    }

    if (OldTime != RealTime)
    {
      menu.DrawTime(hour(), minute(), second());
      OldTime = RealTime;
    }
    // put your main code here, to run repeatedly:

    if (enc1.left())
    {
      if ((frequency - frequencyStep) > 0)
      {
        frequency -= frequencyStep;
      }
      else if ((frequency - frequencyStep) <= 0)
      {
        frequency = 0;
      }
    }
    else if (enc1.right())
    {
      frequency += frequencyStep;
    }
    if (enc2.right() && PWM < 100)
    {
      PWM += 1;
    }
    else if (enc2.left() && PWM > 0)
    {
      PWM -= 1;
    }

    if (btn_1.get())
    {
      if (i <= (sizeof(frequencySteps) / sizeof(frequencySteps[0])) - 2)
      {
        i++;
      }
      frequencyStep = frequencySteps[i];
    }

    if (btn_0.get())
    {
      if (i > 0)
      {
        i--;
      }
      frequencyStep = frequencySteps[i];
    }

    if (btn_12.get())
    {
      preferences.putFloat("freq_memory", frequency);
      MemoryFrequency = frequency;
      preferences.putFloat("PWM_memory", PWM);
    }
    if (btn_13.get())
    {
      frequency = preferences.getFloat("freq_memory", 333333);
      PWM = preferences.getFloat("PWM_memory", 33);
      preferences.end();
    }
    if (esp.status())
    {
      MQTT = " MQTT - ON";
    }
    else if (!esp.status())
    {
      MQTT = " MQTT - OFF";
    }

    period = (1 / frequency) / 100;
    DutyTime = period * PWM;
    if (DutyTime <= 0.01 and DutyTime >= 1.0e-3)
    {
      PrintedDutyTime = DutyTime * 100;
      TimeUnits = " ms";
    }
    else if (DutyTime <= 1.0e-3 and DutyTime >= 1.0e-6)
    {
      PrintedDutyTime = DutyTime * 1000000;
      TimeUnits = " mks";
    }
    else if (DutyTime <= 1.0e-6)
    {
      PrintedDutyTime = DutyTime * 1000000000;
      TimeUnits = " ns";
    }

    if (period <= 0.01 and period >= 1.0e-3)
    {
      StepDutyTime = period * 100;
      StepUnits = " ms";
    }
    else if (period <= 1.0e-3 and period >= 1.0e-6)
    {
      StepDutyTime = period * 1000000;
      StepUnits = " mks";
    }
    else if (period <= 1.0e-6)
    {
      StepDutyTime = period * 1000000000;
      StepUnits = " ns";
    }
    if (frequency == 0)
    {
      StepDutyTime = 0;
      DutyTime = 0;
    }

    pageCounter = 1;
    SubSettings = 1;
  }

  if (digitalRead(34) and !btnflag)
  {
    btnflag = true;
    MainMenuDraw = !MainMenuDraw;
    MainMenuflag = true;
    SubMenuDraw = !SubMenuDraw;
    SubMenuflag = true;
    set_flag = true;
  }
  if (!digitalRead(34) and btnflag)
  {
    btnflag = false;
  }
  // if (SubMenuDraw and SubMenuflag)
  // {
  //   menu.drawSettings(pageCounter, 0x000F, 0xF00F, MenuPages);
  //   SubMenuflag = false;
  // }
  if ((SubMenuDraw) and (MenuLevel == 0))
  {
    if (btn_1.get())
    {
      SubSettings++;
      SubSettings = (SubSettings == 4) ? 0 : SubSettings;
      pageCounter = 1;
      full_clear = !full_clear;
    }

    switch (SubSettings)
    {
    case 1:

      if (enc1.right())
      {
        pageCounter++;
        pageCounter = (pageCounter > 8) ? 1 : pageCounter;
        pageCounter = (pageCounter > 4 && pageCounter < 8) ? 8 : pageCounter; //убирает пустую прокрутку
        SubMenuflag = true;
      }
      else if (enc1.left())
      {
        pageCounter--;
        pageCounter = (pageCounter < 1) ? 8 : pageCounter;
        pageCounter = (pageCounter > 4 && pageCounter < 8) ? 4 : pageCounter; //убирает пустую прокрутку
        SubMenuflag = true;
      }

      if (SubMenuDraw and SubMenuflag)
      {
        menu.drawSettings(pageCounter, 0x000F, 0xF00F, MenuPages);
        SubMenuflag = false;
      }
      menu.drawSubSettings(pageCounter, 0xF00F);
      break;

    case 2:
      if (enc1.right())
      {
        pageCounter++;
        pageCounter = (pageCounter > 8) ? 1 : pageCounter;
        pageCounter = (pageCounter < 4) ? pageCounter : 1;
        SubMenuflag = true;
      }
      else if (enc1.left())
      {
        pageCounter--;
        pageCounter = (pageCounter < 1) ? 8 : pageCounter;
        pageCounter = (pageCounter > 4 && pageCounter < 8) ? 4 : pageCounter; //убирает пустую прокрутку
        SubMenuflag = true;
      }
      menu.drawdSubSettingsChoose(pageCounter, 0xF00F, last_state);
      break;

    case 3:
      menu.drawSubSettingsValue(pageCounter);
      break;

    default:
      break;
    }
  }
}