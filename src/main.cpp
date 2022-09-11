#include <Arduino.h>
#include <Menu.h>

#include <Wire.h>
#include <Adafruit_ADS1015.h>
Adafruit_ADS1115 ads(0x48);

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>
#include <NTPClient.h>
#include <TimeLib.h>
#include <Timer.h>

#include <AD9850_2.h>
AD9850 dds;
#include <EncButton.h>
EncButton<EB_TICK, 32, 33> enc1;
EncButton<EB_TICK, 14, 4> enc2;
// #include <string>
// #include <iostream>
#include <MCP4725.h>// Підключення бібліотеки для роботи з ЦАП MCP4725
MCP4725 dac(0x60);// Створення об'єкту dac і задання йому адреси 0х60 для роботи з MCP4725
#include <MQTT.h>

#include <MCP23017_Buttons.h>

#include <Preferences.h>
Preferences preferences;

#define MY_PERIOD 500  // период в мс
uint32_t tmr1; 

float frequency_memory = 0;
float PWM_memory = 0;
float frequency_modulation_memory = 0;
float PWM_modulation_memory = 0;



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

bool menuState = false;
bool Selectedflag = false;

int SubSettings = 1;
int MenuLevel = 0;
int pageCounter = 1;
int SelectCounter = 1;

float frequency = 0;
float Oldfrequency;

float ModulationFrequency;
float OldModulationFrequency;
float MemoryModulationFrequency;
float DisplayedMemoryModulationFrequency;
float MemoryModulationDuty;
float ModulationDuty;
float OldModulationDuty;
bool Modflag = false;

float ModulationFrequencySteps[] = {0.1f, 1.0f, 10.0f, 100.0f, 1000.0f, 10000.0f, 100000.0f};
int ModulationFrequencyStepSelector = 4;
float ModulationFrequencyStep = ModulationFrequencySteps[ModulationFrequencyStepSelector];
String ModulationFrequencyStepUnit;
int ModulationDutyStepSelector = 4;
float ModulationDutySteps[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
float ModulationDutyStep = ModulationDutySteps[ModulationDutyStepSelector];
float DisplayedModulationFrequency;
float DisplayedModulationFrequencyStep = 0;
float PWM = 0;
float PWM_steps[] = {1, 10, 20, 30, 40, 50, 60, 70, 80, 90, 100};
int PWM_step_selector = 5;
float PWM_step = PWM_steps[PWM_step_selector];
float OldPWM;
int dacValue = 0;

float frequencySteps[] = {0.1f, 1.0f, 10.0f, 100.0f, 1000.0f, 10000.0f, 100000.0f};
int i = 4;
float frequencyStep = frequencySteps[i];
String frequency_units[] = {"Hz", "kHz", "MHz",};
String frequency_unit = "Hz";
String frequency_step_unit = "Hz";
String frequency_memory_unit = "Hz";
String frequency_memory_modulation_unit = "Hz";
float DisplayedFrequency = 0.0f;
float DisplayedFrequencyStep = 0;
float OldFrequencyStep;

String ModulationFrequencyUnit = frequency_units[0];

float Current = 1.0;
float OldCurrent;
int CurrentFactor = 20;
float voltage;
float StartVoltage = 0;

float MemoryFrequency = 0;
float OldMemoryFrequency;
float DisplayedMemoryFrequency = 0;
float MemoryPWM = 0;

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
float adc0;


void setup()
{
  dds.setup();
  Serial.begin(115200);
  Serial.println("1");

  pinMode(34, INPUT);

  ledcAttachPin(12, 11); // Подключаем пин и канал ШИМа
  ledcSetup(11, 0, 8);

  preferences.begin("memory", false);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  WiFi.hostByName("ua.pool.ntp.org", NTP_IP);

  ArduinoOTA.setHostname("a[D]rian");
  ArduinoOTA.begin();

  dds.setup();

  timeClient.begin();
  timeClient.setTimeOffset(10800);
  mcp.begin_I2C(0x20);

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
  PWM_memory = preferences.getFloat("PWM_memory", 33);
  MemoryModulationFrequency = preferences.getFloat("freq_mod_mem", 655555);
  MemoryModulationDuty = preferences.getFloat("freq_mod_PWM", 99);

  if(MemoryFrequency <= 999)
  {
    DisplayedMemoryFrequency = MemoryFrequency;
    frequency_memory_unit =  frequency_units[0];
  }
  if(MemoryFrequency > 999)
  {
    DisplayedMemoryFrequency = MemoryFrequency * 0.001;
    frequency_memory_unit =  frequency_units[1];
  }
  if(MemoryFrequency > 999999)
  {
    DisplayedMemoryFrequency = MemoryFrequency * 0.000001;
    frequency_memory_unit =  frequency_units[2];
  }
  if(MemoryModulationFrequency <= 999)
  {
    DisplayedMemoryModulationFrequency = MemoryModulationFrequency;
    frequency_memory_modulation_unit =  frequency_units[0];
  }
  if(MemoryModulationFrequency > 999)
  {
    DisplayedMemoryModulationFrequency = MemoryModulationFrequency * 0.001;
    frequency_memory_modulation_unit =  frequency_units[1];
  }
  if(MemoryModulationFrequency > 999999)
  {
    DisplayedMemoryModulationFrequency = MemoryModulationFrequency * 0.000001;
    frequency_memory_modulation_unit =  frequency_units[2];
  }

  menu.start();
  menu.cleanDisplay();
  menu.DrawIP(IP);
  menu.DrawFrequency(DisplayedFrequency, frequency, frequency_unit);
  menu.DrawPWM(PWM);
  menu.DrawFrequencyStep(DisplayedFrequencyStep, frequency_step_unit);
  menu.DrawCurrent(Current);
  menu.DrawDutyTime(DutyTime, TimeUnits);
  menu.DrawStepDutyTime(StepDutyTime, StepUnits);
  menu.DrawButton(250, 280, 210, 30, 3, 0xFF20, (((String)DisplayedMemoryFrequency) + " " + frequency_memory_unit));
  menu.DrawButton(30, 280, 210, 30, 3, 0xFF20, MQTT);
  menu.DrawData(day(), month(), year());
  menu.DrawTime(hour(), minute(), second());
  preferences.end();
  esp.MQTT_Setup();

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
  StartVoltage = (ads.readADC_SingleEnded(0)) * 0.1875;
        // считываем с АЦП ADS1115

  // unsigned long newTime = millis();
  // unsigned long oldTime;
  // bool adsflag = false;
  // if(( newTime - oldTime) > 1000)
  // {
  //   adsflag = true;
  //   oldTime = millis();
    
  // } 
}

void loop()
{
  enc1.tick();
  enc2.tick();
  esp.connect(esp.status());
  ArduinoOTA.handle();

  MainSett[0] = "Freq: " + String(DisplayedFrequency, 4) + " " + frequency_unit;
  MainSett[1] ="STEP: " + String(DisplayedFrequencyStep) + " " + frequency_step_unit;
  MainSett[2] = "PWM: " + String(PWM/10) + " %";
  MainSett[3] = "PWM STEP: " + String(PWM_step/10) + " %";
  MainSett[4] = "Current Factor: " + String(CurrentFactor);
  Settings[0] = "Main menu style: " + String(SelectColor);
  Memory[1] = "Memory PWM: " + String(MemoryPWM/10) + " %";
  Memory[2] = "Memory mod. freq: " + String(DisplayedMemoryModulationFrequency) + " " + frequency_memory_modulation_unit;
  Memory[3] = "Memory mod. PWM: " + String(MemoryModulationDuty) + " %";
  ModFreq[0] = "M. Freq: " + String(DisplayedModulationFrequency, 4) + " " + ModulationFrequencyUnit;
  ModFreq[1] = "M. Step: " + String(DisplayedModulationFrequencyStep) + " " + ModulationFrequencyStepUnit;
  ModFreq[2] = "M. DUTY: " + String(ModulationDuty) + " %";
  ModFreq[3] = "M. DUTY STEP:" + String(ModulationDutyStep) + " %";
  dds.setfreq(frequency, 0);

  // if(adsflag)
  // {
    if (millis() - tmr1 >= 1000) {  // ищем разницу
    tmr1 = millis();
    adc0 = ads.readADC_SingleEnded(0);                   // сброс таймера
    // выполнить действие
  }
  //   adsflag = false;
  // }
  //  // (0) - номер канала
  voltage = adc0 * 0.1875;
  Current = (voltage - StartVoltage)/CurrentFactor;

  if(frequency <= 999)
  {
    DisplayedFrequency = frequency;
    frequency_unit = frequency_units[0];
  }
  if(frequency > 999)
    {
      DisplayedFrequency = frequency * 0.001;
      frequency_unit = frequency_units[1];
    }
  if(frequency > 999999)
  {
    DisplayedFrequency = frequency * 0.000001;
    frequency_unit = frequency_units[2];
  }

  if(MemoryFrequency <= 999)
  {
    DisplayedMemoryFrequency = MemoryFrequency;
    frequency_memory_unit =  frequency_units[0];
  }
  if(MemoryFrequency > 999)
  {
    DisplayedMemoryFrequency = MemoryFrequency * 0.001;
    frequency_memory_unit =  frequency_units[1];
  }
  if(MemoryFrequency > 999999)
  {
    DisplayedMemoryFrequency = MemoryFrequency * 0.000001;
    frequency_memory_unit =  frequency_units[2];
  }
if(frequencyStep <= 999)
  {
    DisplayedFrequencyStep = frequencyStep;
    frequency_step_unit = frequency_units[0];
  }
if(frequencyStep > 999)
  {
    DisplayedFrequencyStep = frequencyStep * 0.001;
    frequency_step_unit = frequency_units[1];
  }
if(frequencyStep > 999999)
  {
    DisplayedFrequencyStep = frequencyStep * 0.000001;
    frequency_step_unit = frequency_units[2];
  }
  if(ModulationFrequency <= 999)
    {
                DisplayedModulationFrequency = ModulationFrequency;
                ModulationFrequencyUnit = frequency_units[0];
    }
  if(ModulationFrequency > 999)
    {
      DisplayedModulationFrequency = ModulationFrequency * 0.001;
      ModulationFrequencyUnit = frequency_units[1];
    }
  if(ModulationFrequency > 999999)
    {
      DisplayedModulationFrequency = ModulationFrequency * 0.000001;
      ModulationFrequencyUnit = frequency_units[2];
    }

  if(ModulationFrequencyStep <= 999)
  {
    DisplayedModulationFrequencyStep = ModulationFrequencyStep;
    ModulationFrequencyStepUnit = frequency_units[0];
  }
  if(ModulationFrequencyStep > 999)
  {
    DisplayedModulationFrequencyStep = ModulationFrequencyStep * 0.001;
    ModulationFrequencyStepUnit = frequency_units[1];
  }
  if(ModulationFrequencyStep > 999999)
  {
    DisplayedModulationFrequencyStep = ModulationFrequencyStep * 0.000001;
    ModulationFrequencyStepUnit = frequency_units[2];
  }
  
  if(MemoryModulationFrequency <= 999)
  {
    DisplayedMemoryModulationFrequency = MemoryModulationFrequency;
    frequency_memory_modulation_unit =  frequency_units[0];
  }
  if(MemoryModulationFrequency > 999)
  {
    DisplayedMemoryModulationFrequency = MemoryModulationFrequency * 0.001;
    frequency_memory_modulation_unit =  frequency_units[1];
  }
  if(MemoryModulationFrequency > 999999)
  {
    DisplayedMemoryModulationFrequency = MemoryModulationFrequency * 0.000001;
    frequency_memory_modulation_unit =  frequency_units[2];
  }
  Memory[0] = "Freq. memory: " + String(DisplayedMemoryFrequency) + " " + frequency_memory_unit;
  String RealTime = String(hour()) + ":" + String(minute()) + ":" + String(second());
  String RealData = String(day()) + "-" + String(month()) + "-" + String(year());
  if (MainMenuDraw)
  {
    preferences.begin("memory", false);
    if (MainMenuflag)
    {
      menu.cleanDisplay();
      menu.DrawIP(IP);
      menu.DrawFrequency(DisplayedFrequency, frequency, frequency_unit);
      menu.DrawPWM(PWM/10);
      menu.DrawFrequencyStep(DisplayedFrequencyStep, frequency_step_unit);
      menu.DrawCurrent(Current);
      menu.DrawDutyTime(DutyTime, TimeUnits);
      menu.DrawStepDutyTime(StepDutyTime, StepUnits);
      menu.DrawButton(250, 280, 210, 30, 3, 0xFF20, (((String)DisplayedMemoryFrequency) + " " + frequency_memory_unit));
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
      menu.DrawFrequency(DisplayedFrequency, frequency, frequency_unit);
      esp.MQTT_pub("freq2", frequency);
      Oldfrequency = frequency;
    }

    if (OldPWM != PWM)
    {
      menu.DrawPWM(PWM/10);
      esp.MQTT_pub("PWM3", PWM/10);
      OldPWM = PWM;
    }

    if (OldFrequencyStep != frequencyStep)
    {
      menu.DrawFrequencyStep(DisplayedFrequencyStep, frequency_step_unit);
      esp.MQTT_pub("step1", frequencyStep);
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
      menu.DrawButton(250, 280, 210, 30, 3, 0xFF20, (((String)DisplayedMemoryFrequency) + " " + frequency_memory_unit));
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

    if (enc1.left() or btn_5.get())
    {
      if ((frequency - frequencyStep) >= 0)
      {
        frequency -= frequencyStep;
      }
      else if ((frequency - frequencyStep) < 0)
      {
        frequency = 0;
      }
    }
    else if (enc1.right() or btn_4.get())
    {
      frequency += frequencyStep;
    }
    if (enc2.right())
    {
      if((PWM + PWM_step) <= 1000)
      {
        PWM += PWM_step;
      }
      else if((PWM + PWM_step) > 1000)
      {
        PWM = 1000;
      }
    }
    if(enc2.left())
    {
      if(PWM - PWM_step > 0)
      {
        PWM -= PWM_step;
      }
      else if(PWM - PWM_step <= 0)
      {
        PWM = 0;
      }
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

    if(btn_2.get())
    {
      Modflag = true;
    }
    if(btn_3.get())
    {
      Modflag = false;
    }
    if (btn_12.get())
    {
      preferences.putFloat("freq_memory", frequency);
      MemoryFrequency = frequency;
      esp.MQTT_pub("mem2", MemoryFrequency);
      preferences.putFloat("PWM_memory", PWM);
      MemoryPWM = PWM;
      preferences.putFloat("freq_mod_mem", ModulationFrequency);
      MemoryModulationFrequency = ModulationFrequency;
      preferences.putFloat("freq_mod_PWM", ModulationDuty);
      MemoryModulationDuty = ModulationDuty;
    }
    if (btn_13.get())
    {
      frequency = preferences.getFloat("freq_memory", 333333);
      PWM = preferences.getFloat("PWM_memory", 33);
      ModulationFrequency = preferences.getFloat("freq_mod_mem", 555555);
      ModulationDuty = preferences.getFloat("freq_mod_PWM", 99);
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
      SubSettings = (SubSettings == 4) ? 1 : SubSettings;
      full_clear = !full_clear;
      SubMenuflag = true;
    }

    if (btn_0.get())
    {
      SubSettings--;
      SubSettings = (SubSettings == 0) ? 1 : SubSettings;
      // SelectCounter = 1;
      full_clear = !full_clear;
      SubMenuflag = true;
    }

    switch (SubSettings)
    {
    case 1: 
      if (enc1.right())
      {
        pageCounter++;
        pageCounter = (pageCounter > 8) ? 1 : pageCounter;
        // pageCounter = (pageCounter > 4 && pageCounter < 8) ? 8 : pageCounter; //убирает пустую прокрутку
        SubMenuflag = true;
        SelectCounter = 1;
      }
      else if (enc1.left())
      {
        pageCounter--;
        pageCounter = (pageCounter < 1) ? 8 : pageCounter;
        // pageCounter = (pageCounter > 4 && pageCounter < 8) ? 4 : pageCounter; //убирает пустую прокрутку
        SubMenuflag = true;
        SelectCounter = 1;
      }
      if (SubMenuDraw and SubMenuflag)
      {
        menu.drawSettings(pageCounter, 0x000F, 0xF00F, MenuPages);
        menu.drawSubSettings(pageCounter, 0xF00F);
        SubMenuflag = false;
      }
      break;

    case 2:
      if(SubMenuflag)
        {
          menu.drawSettings(0, 0x000F, 0xF00F, MenuPages);
          SubMenuflag = false;
          Selectedflag = true;
        }
      if(enc1.right())
        {
          SelectCounter++;
          SelectCounter = (SelectCounter > 8) ? 1 : SelectCounter;
          Selectedflag = true;
        }
      if(enc1.left())
        {
          SelectCounter--;
          SelectCounter = (SelectCounter < 1) ? 8 : SelectCounter;
          Selectedflag = true;
        }
      if (SubMenuDraw and Selectedflag)
        {
          menu.drawdSubSettingsChoose(SelectCounter, 0xF00F, pageCounter);
          Selectedflag = false;
        }
      break;
    case 3:
      switch (pageCounter)
      {
        case 1:
          switch (SelectCounter)
          {
          case 1:
            if(enc1.right())
              {
                frequency += frequencyStep;
                  if(frequency <= 999)
                    {
                      DisplayedFrequency = frequency;
                      frequency_unit = frequency_units[0];
                    }
                  if(frequency > 999)
                      {
                        DisplayedFrequency = frequency * 0.001;
                        frequency_unit = frequency_units[1];
                      }
                  if(frequency > 999999)
                    {
                      DisplayedFrequency = frequency * 0.000001;
                      frequency_unit = frequency_units[2];
                    }
                MainSett[0] = "Freq: " + String(DisplayedFrequency, 4) + frequency_unit;
                menu.printFromMassive(0);
              }
              else if(enc1.left())
                {
                  if ((frequency - frequencyStep) > 0)
                    {
                      frequency -= frequencyStep;
                    }
                    else if ((frequency - frequencyStep) <= 0)
                    {
                      frequency = 0;
                    }
                    if(frequency <= 999)
                      {
                        DisplayedFrequency = frequency;
                        frequency_unit = frequency_units[0];
                      }
                    if(frequency > 999)
                      {
                        DisplayedFrequency = frequency * 0.001;
                        frequency_unit = frequency_units[1];
                      }
                    if(frequency > 999999)
                      {
                        DisplayedFrequency = frequency * 0.000001;
                        frequency_unit = frequency_units[2];
                      }
                  MainSett[0] = "Freq: " + String(DisplayedFrequency, 4) + frequency_unit;
                  menu.printFromMassive(0);
                }
          case 2:
            if(enc1.right())
              {
                if (i <= (sizeof(frequencySteps) / sizeof(frequencySteps[0])) - 2)
                {
                  i++;
                }
                frequencyStep = frequencySteps[i];
                  if(frequencyStep <= 999)
                  {
                    DisplayedFrequencyStep = frequencyStep;
                    frequency_step_unit = frequency_units[0];
                  }
                  if(frequencyStep > 999)
                    {
                      DisplayedFrequencyStep = frequencyStep * 0.001;
                      frequency_step_unit = frequency_units[1];
                    }
                  if(frequencyStep > 999999)
                  {
                    DisplayedFrequencyStep = frequencyStep * 0.000001;
                    frequency_step_unit = frequency_units[2];
                  }
                MainSett[1] ="STEP: " + String(DisplayedFrequencyStep) + " " + frequency_step_unit;
                menu.printFromMassive(1);
              }
              else if(enc1.left())
                {
                  if (i > 0)
                  {
                    i--;
                  }
                  frequencyStep = frequencySteps[i];
                  if(frequencyStep <= 999)
                  {
                    DisplayedFrequencyStep = frequencyStep;
                    frequency_step_unit = frequency_units[0];
                  }
                  if(frequencyStep > 999)
                    {
                      DisplayedFrequencyStep = frequencyStep * 0.001;
                      frequency_step_unit = frequency_units[1];
                    }
                  if(frequencyStep > 999999)
                  {
                    DisplayedFrequencyStep = frequencyStep * 0.000001;
                    frequency_step_unit = frequency_units[2];
                  }
                  MainSett[1] ="STEP: " + String(DisplayedFrequencyStep) + " " + frequency_step_unit;
                  menu.printFromMassive(1);
                }
            break;
          case 3:
            if(enc1.right())
            {
              if((PWM + PWM_step) <= 1000)
                {
                  PWM += PWM_step;
                }
              else if((PWM + PWM_step) > 1000)
                {
                  PWM = 1000;
                }
              MainSett[2] = "PWM: "  + String(PWM/10) + "%";
              menu.printFromMassive(2);
            }
            if(enc1.left())
            {
              if(PWM - PWM_step > 0)
                {
                  PWM -= PWM_step;
                }
                else if(PWM - PWM_step <= 0)
                {
                  PWM = 0;
                }
              MainSett[2] = "PWM: "  + String(PWM/10) + "%";
              menu.printFromMassive(2);
            }
            break;
          case 4:
            if(enc1.right())
            {
              if(PWM_step_selector < ((sizeof(PWM_steps)/sizeof(PWM_steps[0])) - 1))
              { 
                PWM_step_selector++;
                PWM_step = PWM_steps[PWM_step_selector];
                MainSett[3] = "PWM STEP: " + String(PWM_step/10) + "%";
                menu.printFromMassive(3);
              }
            }
            else if(enc1.left())
            {
              if(PWM_step_selector > 0)
              {
                PWM_step_selector--;
                PWM_step = PWM_steps[PWM_step_selector];
                MainSett[3] = "PWM STEP: " + String(PWM_step/10) + "%";
                menu.printFromMassive(3);
              }
            }
            break;
          case 5:
          if(enc1.right())
          {
            if((CurrentFactor + 1) < 60)
            {
              CurrentFactor++;
              MainSett[4] = "Current Factor: " + String(CurrentFactor);
              menu.printFromMassive(4);
            }
            if((CurrentFactor + 1) >= 60)
            {
              CurrentFactor = 60;
              MainSett[4] = "Current Factor: " + String(CurrentFactor);
              menu.printFromMassive(4);
            }
            
          }
          if(enc1.left())
          { 
            if((CurrentFactor - 1) > 0)
            {
              CurrentFactor--;
              MainSett[4] = "Current Factor: " + String(CurrentFactor);
              menu.printFromMassive(4);
            }
            if((CurrentFactor - 1) <= 0)
            {
              CurrentFactor = 0;
              MainSett[4] = "Current Factor: " + String(CurrentFactor);
              menu.printFromMassive(4);
            }
            
          }
            break;
          default:
            break;
          }
          break;
        case 2:
        switch (SelectCounter)
        {
        case 1:
          if(enc1.right())
          {
            ModulationFrequency += ModulationFrequencyStep;
            if(ModulationFrequency <= 999)
              {
                DisplayedModulationFrequency = ModulationFrequency;
                ModulationFrequencyUnit = frequency_units[0];
              }
            if(ModulationFrequency > 999)
              {
                DisplayedModulationFrequency = ModulationFrequency * 0.001;
                ModulationFrequencyUnit = frequency_units[1];
              }
            if(ModulationFrequency > 999999)
              {
                DisplayedModulationFrequency = ModulationFrequency * 0.000001;
                ModulationFrequencyUnit = frequency_units[2];
              }
            ModFreq[0] = "M. Freq: " + String(DisplayedModulationFrequency, 4) + " " + ModulationFrequencyUnit;
            esp.MQTT_pub("freqmod2", ModulationFrequency);
            menu.printFromModulation(0);
          }
          if(enc1.left())
          {
            if((ModulationFrequency - ModulationFrequencyStep) >= 0)
            {
              ModulationFrequency -= ModulationFrequencyStep;
            }
            if((ModulationFrequency - ModulationFrequencyStep) < 0)
            {
              ModulationFrequency = 0;
            }
            if(ModulationFrequency <= 999)
              {
                DisplayedModulationFrequency = ModulationFrequency;
                ModulationFrequencyUnit = frequency_units[0];
              }
            if(ModulationFrequency > 999)
              {
                 DisplayedModulationFrequency = ModulationFrequency * 0.001;
                ModulationFrequencyUnit = frequency_units[1];
              }
            if(ModulationFrequency > 999999)
              {
                DisplayedModulationFrequency = ModulationFrequency * 0.000001;
                ModulationFrequencyUnit = frequency_units[2];
              }
            ModFreq[0] = "M. Freq: " + String(DisplayedModulationFrequency, 4) + " " + ModulationFrequencyUnit;
            esp.MQTT_pub("freqmod2", ModulationFrequency);
            menu.printFromModulation(0);
          }
          break;
        case 2:
          if(enc1.right())
          {
            if(ModulationFrequencyStepSelector < (sizeof(ModulationFrequencySteps)/sizeof(ModulationFrequencySteps[0])) - 1)
            {
              ModulationFrequencyStepSelector++;
              ModulationFrequencyStep = ModulationFrequencySteps[ModulationFrequencyStepSelector];
            }
            if(ModulationFrequencyStep <= 999)
              {
                DisplayedModulationFrequencyStep = ModulationFrequencyStep;
                ModulationFrequencyStepUnit = frequency_units[0];
              }
            if(ModulationFrequencyStep > 999)
              {
                DisplayedModulationFrequencyStep = ModulationFrequencyStep * 0.001;
                ModulationFrequencyStepUnit = frequency_units[1];
              }
            if(ModulationFrequencyStep > 999999)
              {
                DisplayedModulationFrequencyStep = ModulationFrequencyStep * 0.000001;
                ModulationFrequencyStepUnit = frequency_units[2];
              }
            ModFreq[1] = "M. Step: " + String(DisplayedModulationFrequencyStep) + " " + ModulationFrequencyStepUnit;
            esp.MQTT_pub("mod.step1", ModulationFrequencyStep);
            menu.printFromModulation(1);
          }
          if(enc1.left())
          {
            if(ModulationFrequencyStepSelector > 0)
            {
              ModulationFrequencyStepSelector--;
              ModulationFrequencyStep = ModulationFrequencySteps[ModulationFrequencyStepSelector];
            }
            if(ModulationFrequencyStep <= 999)
              {
                DisplayedModulationFrequencyStep = ModulationFrequencyStep;
                ModulationFrequencyStepUnit = frequency_units[0];
              }
            if(ModulationFrequencyStep > 999)
              {
                DisplayedModulationFrequencyStep = ModulationFrequencyStep * 0.001;
                ModulationFrequencyStepUnit = frequency_units[1];
              }
            if(ModulationFrequencyStep > 999999)
              {
                DisplayedModulationFrequencyStep = ModulationFrequencyStep * 0.000001;
                ModulationFrequencyStepUnit = frequency_units[2];
              }
            ModFreq[1] = "M. Step: " + String(DisplayedModulationFrequencyStep) + " " + ModulationFrequencyStepUnit;
            esp.MQTT_pub("mod.step1", ModulationFrequencyStep);
            menu.printFromModulation(1);
          }
          break;

        case 3:
        if(enc1.right())
        {
          if((ModulationDuty + ModulationDutyStep) <= 100)
          {
            ModulationDuty += ModulationDutyStep;
          }
          if((ModulationDuty + ModulationDutyStep) > 100)
          {
            ModulationDuty = 100;
          }
          ModFreq[2] = "M. DUTY: " + String(ModulationDuty) + " %";
          menu.printFromModulation(2);
        }
        
        if(enc1.left())
        {
          if((ModulationDuty - ModulationDutyStep) > 0)
          {
            ModulationDuty -= ModulationDutyStep;
          }
          if((ModulationDuty - ModulationDutyStep) <= 0)
          {
            ModulationDuty = 0;
          }
          ModFreq[2] = "M. DUTY: " + String(ModulationDuty) + " %";
          menu.printFromModulation(2);
        }
          break;

        case 4:
        if(enc1.right())
        {
          if(ModulationDutyStepSelector < (sizeof(ModulationDutySteps)/sizeof(ModulationDutySteps[0]) - 1))
          {
            ModulationDutyStepSelector++;
          }
          ModulationDutyStep = ModulationDutySteps[ModulationDutyStepSelector];
          ModFreq[3] = "M. DUTY STEP:" + String(ModulationDutyStep) + " %";
          menu.printFromModulation(3);
          
        }
        if(enc1.left())
        {
          if(ModulationDutyStepSelector > 0)
          {
            ModulationDutyStepSelector--;
          }
          ModulationDutyStep = ModulationDutySteps[ModulationDutyStepSelector];
          ModFreq[3] = "M. DUTY STEP:" + String(ModulationDutyStep) + " %";
          menu.printFromModulation(3);
        }
          break;

        default:
          break;
        }
          break;

        case 3:
          break;

        case 4:
          break;

        case 5:
          break;

        case 6:
          break;

        case 7:
          break;

        case 8:
        switch(SelectCounter)
        {
          case 1:
            if(enc1.right())
            {
              if((SelectColor + 1) <= 3)
              {
                SelectColor++;
              }
              else if((SelectColor + 1) > 3)
              {
                SelectColor = 0;
              }
              Settings[0] = "Main menu style: " + String(SelectColor);
              menu.printFromSettings(0);
            }
            if(enc1.left())
            {
              if((SelectColor - 1) >= 0)
              {
                SelectColor--;
              }
              else if((SelectColor - 1) < 0)
              {
                SelectColor = 3;
              }
              Settings[0] = "Main menu style: " + String(SelectColor);
              menu.printFromSettings(0);
            }
            break;
        }
          break;

        default:
          break;
      }
      break;
    default:
      break;
    }
  }
  dacValue = map(PWM, 0, 1000, 1260, 30);
  dacValue = constrain(dacValue, 30, 1260);
  dac.setValue(dacValue);
  dds.setfreq(frequency,0);
  if(Modflag)
  {
    if(ModulationDuty != OldModulationDuty or ModulationFrequency != OldModulationFrequency or Modflag)
    {
      if(ModulationFrequency != 0)
      {
        ledcSetup(11, ModulationFrequency, 8);
        ledcWrite(11, map(ModulationDuty, 0, 100, 0, 255));
      }
      if(ModulationFrequency == 0)
      {
        ledcSetup(11, 0, 8);
        ledcWrite(11, 0);
      }
      OldModulationDuty = ModulationDuty;
      OldModulationFrequency = ModulationFrequency;
    }
  }
  if(!Modflag)
  {
    ledcSetup(11, 0, 8);
    ledcWrite(11, 0);
  }
}