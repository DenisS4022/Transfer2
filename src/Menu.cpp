#include "Menu.h"
#include "Bitmap.h"
#include <TFT_eSPI.h>

String MenuPages[] = {"Main Sett.",
                      "Mod Freq.",
                      "Memory",
                      "Resonance",
                      " ",
                      " ",
                      " ",
                      "Settings"};

String MainSett[] = {"Freq: 0.00",
                     "STEP: 1000.00",
                     "PWM: 0%",
                     "PWM STEP: 5%",
                     "Current Factor"};

String ModFreq[] = {"M.Step",
                    "M.Freq",
                    "MOD DUTY STEP",
                    "MOD DUTY"};

String Memory[] = {"Memory freq",
                   "Memory PWM",
                   "Memory mod. freq",
                   "Memory mod. PWM"};

String Resonance[] = {"Freq. step",
                      "Min. freq",
                      "Max. freq",
                      "Time interval",
                      "Current",
                      "Present freq.",
                      "Resonance freq.",
                      "Max current"};

int draw_line1;
int previous_value1;
int previous_value2;
int last_state;
bool set_flag = false;
bool full_clear = false;

TFT_eSPI tft = TFT_eSPI();
void Menu::start()
{
  tft.init();
  tft.setRotation(3);
  tft.fillScreen(0x0000);
  tft.setFreeFont(&FreeSerif12pt7b);
  tft.print("L13");
}
void Menu::cleanDisplay()
{
  tft.fillScreen(0x0000);
}

void Menu::DrawIP(String IP)
{
  tft.fillRect(200, 0, 190, 33, 0x0000);
  tft.setCursor(200, 30);
  tft.setTextColor(0x0778);
  tft.print("IP: ");
  tft.print(IP);
  tft.drawRoundRect(199, 34, 43, 27, 3, 0xFF20);
  tft.setCursor(200, 55);
  tft.print("L13");
}

void Menu::DrawFrequency(float frequency, String Unit)
{
  tft.fillRect(180, 100, 180, 25, 0x0000);
  tft.setCursor(30, 120);
  tft.setTextSize(1);
  tft.setTextColor(0x0778);
  tft.print("FREQUENCY:");
  tft.print(String(frequency) + " ");
  tft.print(Unit);
  draw_line1 = map((int)frequency, 0, 1000000, 0, 420);
  draw_line1 = constrain(draw_line1, 0, 420);
  tft.fillRect(30, 128, draw_line1, 18, 0x0FF0);
  if (frequency < previous_value1)
  {
    tft.fillRect(31, 128, 418, 18, 0x0000);
    tft.fillRect(30, 128, draw_line1, 18, 0x0FF0);
  }
  previous_value1 = frequency;
  tft.drawRoundRect(30, 127, 420, 20, 2, 0xFFFF);
  for (int i = 40; i < 450; i += 10)
  {
    tft.fillRect(i, 144, 1, 2, 0xFFFF);
  }
  for (int i = 80; i < 450; i += 50)
  {
    tft.fillRect(i, 142, 2, 4, 0xFFFF);
  }
}
void Menu::DrawPWM(float PWM)
{
  tft.fillRect(180, 150, 180, 25, 0x0000);
  tft.setCursor(30, 170);
  tft.setTextColor(0x0778);
  tft.print("DUTY CYCLE: ");
  tft.print(PWM);
  tft.print(" %");
  int DutyDraw = (int)PWM;
  int draw_line2 = map(DutyDraw, 0, 100, 0, 420);
  draw_line2 = constrain(draw_line2, 0, 420);
  tft.fillRect(30, 178, draw_line2, 18, 0x0FF0);
  if (PWM < previous_value2)
  {
    tft.fillRect(31, 178, 418, 18, 0x0000);
    tft.fillRect(30, 178, draw_line2, 18, 0x0FF0);
  }
  previous_value2 = PWM;
  tft.drawRoundRect(30, 177, 420, 20, 2, 0xFFFF);
  for (int i = 40; i < 450; i += 10)
  {
    tft.fillRect(i, 194, 1, 2, 0xFFFF);
  }
  for (int i = 130; i < 450; i += 100)
  {
    tft.fillRect(i, 192, 2, 4, 0xFFFF);
  }
}
void Menu::DrawBitmaps()
{
  tft.drawBitmap(393, 8, WiFi_13, 25, 25, 0xFFFF);
  tft.drawBitmap(425, 10, Battery_1, 25, 25, 0xFFFF);
  tft.drawBitmap(425, 10, Battery_2, 25, 25, 0x0778);
}

void Menu::DrawFrequencyStep(float frequencyStep)
{
  tft.fillRect(30, 62, 200, 30, 0x0000);
  tft.setCursor(30, 85);
  tft.setTextColor(0x0778);
  tft.print("STEP: ");
  tft.print(frequencyStep);
  tft.print("Hz");
}

void Menu::DrawCurrent(float Current)
{
  tft.fillRect(120, 210, 100, 23, 0x0000);
  tft.setCursor(30, 230);
  tft.setTextColor(0x0778);
  tft.print("Current: ");
  tft.print(Current);
  tft.print(" A");
}

void Menu::DrawButton(int16_t x_position, int16_t y_position, int16_t width, int16_t height, int16_t radius, uint16_t color, String name)
{
  tft.fillRect(x_position, y_position, width, height, 0x0000);
  int count = 0;
  while (count < 3)
  {
    tft.drawRoundRect(x_position + count, y_position, width, height, radius, color);
    count++;
  }
  tft.setTextColor(0xFFFF);
  tft.setCursor(x_position + 6, y_position + 24);
  tft.print(name);
}

void Menu::DrawTime(int hour, int minute, int second)
{
  String seconds;
  String hours;
  String minutes;
  if (second < 10)
  {
    seconds = "0" + String(second);
  }
  else
  {
    seconds = String(second);
  }

  if (minute < 10)
  {
    minutes = "0" + String(minute);
  }
  else
  {
    minutes = String(minute);
  }
  if (hour < 10)
  {
    hours = "0" + String(hour);
  }
  else
  {
    hours = String(hour);
  }

  tft.fillRect(30, 0, 120, 33, 0x0000);
  tft.setCursor(30, 30);
  tft.setTextColor(0xFFFF);
  tft.print(hours + ":" + minutes + ":" + seconds);
}
void Menu::DrawData(int day, int month, int year)
{
  String days;
  String months;
  String years;
  if (day < 10)
  {
    days = "0" + String(day);
  }
  else
  {
    days = day;
  }

  if (month < 10)
  {
    months = "0" + String(month);
  }
  else
  {
    months = month;
  }

  if (year < 10)
  {
    years = "0" + String(year);
  }
  else
  {
    years = year;
  }
  tft.fillRect(30, 33, 120, 33, 0x0000);
  tft.setTextColor(0xFFFF);
  tft.setCursor(30, 55);
  tft.print(days + ":" + months + ":" + years);
}

void Menu::DrawDutyTime(float DutyTime, String TimeUnits)
{
  tft.fillRect(105, 235, 120, 23, 0x0000);
  tft.setCursor(30, 255);
  tft.setTextColor(0x0778);
  tft.print("DUTY: ");
  tft.print(DutyTime);
  tft.print(TimeUnits);
}

void Menu::DrawStepDutyTime(float StepDutyTime, String StepUnits)
{
  tft.fillRect(300, 235, 150, 23, 0x0000);
  tft.setCursor(230, 255);
  tft.setTextColor(0x0778);
  tft.print("STEP: ");
  tft.print(StepDutyTime);
  tft.print(StepUnits);
}
int Menu::drawSettings(int pageCounter, int MenuColor, int SubTextColor, String Strings[8])
{
  switch (pageCounter)
  {
  case 1:
    menu(SubTextColor, MenuColor, Strings);
    tft.fillRect(0, 0, 140, 40, TFT_WHITE);
    tft.setTextColor(TFT_BLUE);
    tft.setCursor(0, 25);
    tft.print(Strings[0]);
    break;
  case 2:
    menu(SubTextColor, MenuColor, Strings);
    tft.fillRect(0, 40, 140, 40, TFT_WHITE);
    tft.setTextColor(TFT_BLUE);
    tft.setCursor(0, 65);
    tft.print(Strings[1]);
    break;
  case 3:
    menu(SubTextColor, MenuColor, Strings);
    tft.fillRect(0, 80, 140, 40, TFT_WHITE);
    tft.setTextColor(TFT_BLUE);
    tft.setCursor(0, 105);
    tft.print(Strings[2]);
    break;
  case 4:
    menu(SubTextColor, MenuColor, Strings);
    tft.fillRect(0, 120, 140, 40, TFT_WHITE);
    tft.setTextColor(TFT_BLUE);
    tft.setCursor(0, 145);
    tft.print(Strings[3]);
    break;
  case 5:
    menu(SubTextColor, MenuColor, Strings);
    tft.fillRect(0, 160, 140, 40, TFT_WHITE);
    tft.setTextColor(TFT_BLUE);
    tft.setCursor(0, 185);
    tft.print(Strings[4]);
    break;
  case 6:
    menu(SubTextColor, MenuColor, Strings);
    tft.fillRect(0, 200, 140, 40, TFT_WHITE);
    tft.setTextColor(TFT_BLUE);
    tft.setCursor(0, 225);
    tft.print(Strings[5]);
    break;
  case 7:
    menu(SubTextColor, MenuColor, Strings);
    tft.fillRect(0, 240, 140, 40, TFT_WHITE);
    tft.setTextColor(TFT_BLUE);
    tft.setCursor(0, 265);
    tft.print(Strings[6]);
    break;
  case 8:
    menu(SubTextColor, MenuColor, Strings);
    tft.fillRect(0, 280, 140, 40, TFT_WHITE);
    tft.setTextColor(TFT_BLUE);
    tft.setCursor(0, 305);
    tft.print(Strings[7]);
    break;
  default:
    menu(SubTextColor, MenuColor, Strings);
    break;
  }

  last_state = pageCounter;
  return last_state;
}

void Menu::drawSubSettings(int pageCounter, int SubTextColor)
{
  if (full_clear)
  {
    tft.fillRect(140, 0, 480, 320, 0x000F);
    full_clear = false;
  }

  static int prev_pageCounter;
  if (prev_pageCounter != pageCounter)
    tft.fillRect(140, 0, 340, 320, 0x000F);
  tft.setTextColor(SubTextColor);

  switch (pageCounter)
  {
  case 1:
    for (int i = 0; i < sizeof(MainSett) / sizeof(MainSett[0]); i++)
    {
      tft.setCursor(140, 25 + i * 40);
      tft.println(MainSett[i]);
    }
    break;

  case 2:
    for (int i = 0; i < sizeof(ModFreq) / sizeof(ModFreq[0]); i++)
    {
      tft.setCursor(140, 25 + i * 40);
      tft.println(ModFreq[i]);
    }
    break;

  case 3:
    for (int i = 0; i < sizeof(Memory) / sizeof(Memory[0]); i++)
    {
      tft.setCursor(140, 25 + i * 40);
      tft.println(Memory[i]);
    }
    break;

  case 4:
    for (int i = 0; i < sizeof(Resonance) / sizeof(Resonance[0]); i++)
    {
      tft.setCursor(140, 25 + i * 40);
      tft.println(Resonance[i]);
    }
    break;
  }

  if (digitalRead(34))
    prev_pageCounter = 0;
  else
    prev_pageCounter = pageCounter;
}

void Menu::drawdSubSettingsChoose(int pageCounter, int SubTextColor, int last_state)
{
  static int prev_pageCounter;
  set_flag = true;
  if (full_clear)
  {
    tft.fillRect(140, 0, 480, 320, 0x000F);
    for (int i = 0; i < 8; i++)
    {
      tft.setCursor(0, 25 + i * 40);
      tft.print(MenuPages[i]);
    }
    full_clear = false;
  }

  if (prev_pageCounter != pageCounter)
  {
    tft.fillRect(140, 0, 340, 320, 0x000F);
    set_flag = true;
  }

  tft.setTextColor(SubTextColor);

  if (set_flag)
  {
    tft.fillRect(140, ((pageCounter - 1) * 40), 440, 40, TFT_WHITE);
    set_flag = false;
  }

  switch (last_state)
  {
  case 1:
    for (int i = 0; i < sizeof(MainSett) / sizeof(MainSett[0]); i++)
    {
      tft.setCursor(140, 25 + i * 40);
      tft.println(MainSett[i]);
    }
    break;

  case 2:
    for (int i = 0; i < sizeof(ModFreq) / sizeof(ModFreq[0]); i++)
    {
      tft.setCursor(140, 25 + i * 40);
      tft.println(ModFreq[i]);
    }
    break;

  case 3:
    for (int i = 0; i < sizeof(Memory) / sizeof(Memory[0]); i++)
    {
      tft.setCursor(140, 25 + i * 40);
      tft.println(Memory[i]);
    }
    break;

  case 4:
    for (int i = 0; i < sizeof(Resonance) / sizeof(Resonance[0]); i++)
    {
      tft.setCursor(140, 25 + i * 40);
      tft.println(Resonance[i]);
    }
    break;
  }

  if (digitalRead(34))
    prev_pageCounter = 0;
  else
    prev_pageCounter = pageCounter;
}

void Menu::menu(int TextColor, int MenuColor, String Strings[8])
{
  tft.fillRect(0, 0, 480, 320, MenuColor);
  tft.setTextColor(TextColor);
  tft.setCursor(0, 25);
  tft.print(Strings[0]);
  tft.setCursor(0, 65);
  tft.print(Strings[1]);
  tft.setCursor(0, 105);
  tft.print(Strings[2]);
  tft.setCursor(0, 145);
  tft.print(Strings[3]);
  tft.setCursor(0, 185);
  tft.print(Strings[4]);
  tft.setCursor(0, 225);
  tft.print(Strings[5]);
  tft.setCursor(0, 265);
  tft.print(Strings[6]);
  tft.setCursor(0, 305);
  tft.print(Strings[7]);
}

void Menu::printFrequencySubMenu(String frequency_str)
{
  tft.fillRect(140, 0, 440, 40, TFT_WHITE);
  tft.setCursor(140, 25);
  tft.println(frequency_str);
}
void Menu::printFromMassive(int i)
{
  tft.fillRect(140, (i * 40), 440, 40, TFT_WHITE);
  tft.setCursor(140, 25 + i * 40);
  tft.println(MainSett[i]);
}
Menu menu = Menu();