#include "Platform_Types.h"
#include "Std_Types.h"
#include "Port.h"
#include "DIO.h"

int main(void)
{
	uint8 Value=0;
	Port_Init();
	DIO_SetPortValue(GPIO_PORTA,0xff);
	Value=DIO_ReadPort(GPIO_PORTA);
	DIO_SetPinValue(GPIO_PORTA,GPIO_PIN0,GPIO_PIN_LOW);
	Value=DIO_ReadPIN(GPIO_PORTF,GPIO_PIN5);
	while(1);
}
