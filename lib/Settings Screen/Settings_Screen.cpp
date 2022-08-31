#include <Settings_Screen.h>

void drawSettings(int pageCounter)
{
    switch (pageCounter)
    {
    case 1:
        menu(SubTextColor);
        tft.fillRect(0, 0, 140, 40, TFT_WHITE);
        tft.setTextColor(TFT_BLUE);
        tft.setCursor(0, 25);
        tft.print(String_1);
        break;
    case 2:
        menu(SubTextColor);
        tft.fillRect(0, 40, 140, 40, TFT_WHITE);
        tft.setTextColor(TFT_BLUE);
        tft.setCursor(0, 65);
        tft.print(String_2);
        break;
    case 3:
        menu(SubTextColor);
        tft.fillRect(0, 80, 140, 40, TFT_WHITE);
        tft.setTextColor(TFT_BLUE);
        tft.setCursor(0, 105);
        tft.print(String_3);
        break;
    case 4:
        menu(SubTextColor);
        tft.fillRect(0, 120, 140, 40, TFT_WHITE);
        tft.setTextColor(TFT_BLUE);
        tft.setCursor(0, 145);
        tft.print(String_4);
        break;
    case 5:
        menu(SubTextColor);
        tft.fillRect(0, 160, 140, 40, TFT_WHITE);
        tft.setTextColor(TFT_BLUE);
        tft.setCursor(0, 185);
        tft.print(String_5);
        break;
    case 6:
        menu(SubTextColor);
        tft.fillRect(0, 200, 140, 40, TFT_WHITE);
        tft.setTextColor(TFT_BLUE);
        tft.setCursor(0, 225);
        tft.print(String_6);
        break;
    case 7:
        menu(SubTextColor);
        tft.fillRect(0, 240, 140, 40, TFT_WHITE);
        tft.setTextColor(TFT_BLUE);
        tft.setCursor(0, 265);
        tft.print(String_7);
        break;
    case 8:
        menu(SubTextColor);
        tft.fillRect(0, 280, 140, 40, TFT_WHITE);
        tft.setTextColor(TFT_BLUE);
        tft.setCursor(0, 305);
        tft.print(String_8);
        break;
    default:
        menu(SubTextColor);
        break;
    }
}

void menu(int TextColor)
{
    tft.fillRect(0, 0, 140, 320, MenuColor);
    tft.setTextColor(TextColor);
    tft.setCursor(0, 25);
    tft.print(String_1);
    tft.setCursor(0, 65);
    tft.print(String_2);
    tft.setCursor(0, 105);
    tft.print(String_3);
    tft.setCursor(0, 145);
    tft.print(String_4);
    tft.setCursor(0, 185);
    tft.print(String_5);
    tft.setCursor(0, 225);
    tft.print(String_6);
    tft.setCursor(0, 265);
    tft.print(String_7);
    tft.setCursor(0, 305);
    tft.print(String_8);
}