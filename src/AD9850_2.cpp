#include <AD9850_2.h>

#define DATA 27
#define FQ_UD 25
#define W_CLK 13

bool En;
float ZQ_Freq;
float Tuning_Freq;
float Freq;
byte Phase;
bool PowerOff;
unsigned long Frequency;
byte Control;
byte N;

void AD9850::setup()
{
	pinMode(27 , OUTPUT);
    pinMode(16 , OUTPUT);
    pinMode(13 , OUTPUT);
    //digitalWrite(RESET, LOW);
    digitalWrite(27 , LOW);
    digitalWrite(16 , LOW);
    digitalWrite(13 , LOW);
}

void AD9850::setfreq(float frequency, byte phase)
{
   	En = 1;
    ZQ_Freq = 125000000.00;
    Tuning_Freq = 1.00;
    Freq = frequency;
    Phase = phase;
    PowerOff = 0;
      if (En)
    {
        	Control =  Phase << 3; // регистр подстройки
        	bitWrite(Control, 2, PowerOff); // бит Power-down
        	Frequency = Freq * Tuning_Freq * 4294967295 / ZQ_Freq; // вычисляем частоту. Частота домножается на 4294967295 / 125000000 .  Частота кварца 125000000
        	for (N=0; N<32; N++)  // передаем частоту
        	
        {
            	if (bitRead(Frequency, N))
            	
            {
                digitalWrite(27, HIGH);
            }
            	else
            	
            {
                digitalWrite(27, LOW);
            }
            	digitalWrite(13, HIGH);
            	digitalWrite(13, LOW);
            	
        }
        	for (N=0; N<8; N++)  // передаем фазу и контроль
        	
        {
            	if (bitRead(Control , N))
            	
            {
                digitalWrite(27, HIGH);
            }
            	else
            	
            {
                digitalWrite(27, LOW);
            }
            	digitalWrite(13, HIGH);
            	digitalWrite(13, LOW);
            	
        }
        	digitalWrite(16, HIGH); // завершаем передачу
        	digitalWrite(16, LOW);
    }
} 
