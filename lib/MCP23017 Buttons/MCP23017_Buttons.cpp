#include <MCP23017_Buttons.h>

Adafruit_MCP23X17 mcp;

bool Buttons::get()
{
    butt = mcp.digitalRead(pin);

    if (butt == 1 && flag_button_state == 0 && millis() - last_press > 200)
    {
        flag_button_state = 1;
        last_press = millis();
        return true;
    }

    if (butt == 0 && flag_button_state == 1)
    {
        flag_button_state = 0;
        return false;
    }

    return false;
}