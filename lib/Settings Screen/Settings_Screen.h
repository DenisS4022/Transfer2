#pragma once

#include <Arduino.h>
#include <SPI.h>
#include "Adafruit_GFX.h"
#include "Adafruit_ST7796S_kbv.h"
#include "Fonts/FreeSerif12pt7b.h"

#define TFT_CS 15
#define TFT_DC 2
#define TFT_RST 5

#define TFT_WHITE 0xFFFF
#define TFT_BLUE 0x00F0
#define MenuColor 0x000F
#define SubTextColor 0xF00F

const String String_1 = "1";
const String String_2 = "2";
const String String_3 = "3";
const String String_4 = "4";
const String String_5 = "5";
const String String_6 = "6";
const String String_7 = "7";
const String String_8 = "8";

extern Adafruit_ST7796S_kbv tft;

void drawSettings(int pageCounter);
void menu(int TextColor);
