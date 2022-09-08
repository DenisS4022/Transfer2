#ifndef Menu_h
#define Menu_h
#include <TFT_eSPI.h>

extern String MenuPages[];
extern String MainSett[];
extern String ModFreq[];
extern String Memory[];
extern String Resonance[];
extern String Settings[];
extern int SelectColor;
class Menu
{
    public:
        void start();
        void cleanDisplay();
        void DrawIP(String IP);
        void DrawFrequency(float DispFreq, float frequency, String Unit);
        void DrawFrequencyStep(float frequencyStep, String Unit);
        void DrawPWM(float PWM);
        void DrawBitmaps();
        void DrawCurrent(float Current);
        void DrawButton(int16_t x_position, int16_t y_position, int16_t width, int16_t height, int16_t radius, uint16_t color, String name);
        void DrawTime(int hour, int minute, int second);
        void DrawData(int day, int month, int year );
        void DrawDutyTime(float DutyTime, String TimeUnits);
        void DrawStepDutyTime(float StepDutyTime, String StepUnits);
        int drawSettings(int pageCounter, int MenuColor, int SubTextColor, String Strings[8]);
        void drawSubSettings(int pageCounter, int SubTextColor);
        void drawdSubSettingsChoose(int pageCounter, int SubTextColor, int last_state);
        void menu(int TextColor, int MenuColor, String Strings[8]);
        void printFrequencySubMenu(String frequency_str);
        void printFromMassive(int i);
        void printFromSettings(int Changed);
        void printFromModulation(int printed);
};

extern Menu menu;
#endif
