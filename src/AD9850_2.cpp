#include <AD9850_2.h>

#define DATA 27
#define FQ_UD 25
#define W_CLK 13

unsigned long Frequency;
float ZQ_Freq = 125000000;
byte Control;
byte N;

void AD9850::setup()
{
pinMode( DATA , OUTPUT);
pinMode( FQ_UD , OUTPUT);
pinMode( W_CLK , OUTPUT);

digitalWrite( DATA , LOW);
digitalWrite( FQ_UD , LOW);
digitalWrite( W_CLK , LOW);
}

void AD9850::setfreq(float frequency, byte phase)
{
   	Control =  phase << 3; // регистр подстройки
	bitWrite(Control, 2, false); // бит Power-down
	Frequency = frequency *1.00000000 * (4294967295 / ZQ_Freq); // вычисляем частоту. Частота домножается на 4294967295 / 125000000 .  Частота кварца 125000000
	for (N=0; N<32; N++) // передаем частоту
	{
		if (bitRead( Frequency, N))
		{
			digitalWrite( DATA, HIGH);
		}
		else
		{
			digitalWrite( DATA, LOW);
		}
		digitalWrite( W_CLK, HIGH);
		digitalWrite( W_CLK, LOW);
	}
	for (N=0; N<8; N++) // передаем фазу и контроль
	{
		if (bitRead( Control , N))
	{	
		digitalWrite( DATA, HIGH);
	}
	else
	{
		digitalWrite( DATA, LOW);
	}
	digitalWrite( W_CLK, HIGH);
	digitalWrite( W_CLK, LOW);
	}
	digitalWrite( FQ_UD, HIGH); // завершаем передачу
	digitalWrite( FQ_UD, LOW); 
} 
