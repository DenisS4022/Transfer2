/*
   1. Подключить библиотеку <MCP23017_Buttons.h>
   2. Добавыть mcp.begin_I2C(0x20); в Setup програмы
   3. Создать обьект и передать в конструктор номер пина Buttons btn_0 = Buttons(0);
   4. Функция btn_0.get(); возвращает true при нажатии кнопки
*/

#pragma once
#include <Arduino.h>
#include <Adafruit_MCP23X17.h>

extern Adafruit_MCP23X17 mcp;

class Buttons
{
public:
    Buttons(int _pin)
    {
        pin = _pin;
    }
    bool get();
    bool flag_button_state = false;
    bool butt;
    unsigned long last_press;
    int pin;
};
