#include "Platform_Types.h"
#include "Std_Types.h"
#include "Port.h"
#include "DIO.h"
#include "STK.h"
#include "IntCtrl.h"

void LED_ON_OFF(void);

int main(void)
{
	IntCtr_Init();
	Port_Init();
	STK_SetTime(5,2);
	STK_SetCallBack(&LED_ON_OFF);
	STK_init();
	while(1);
}

void LED_ON_OFF(void)
{
	static uint32 counter=0;
	uint32 OvflowTime= OnTimeMS + OffTimeMS;	
	counter++;
	if(counter == OffTimeMS)
	{
		DIO_SetPinValue(GPIO_PORTF,GPIO_PIN1,GPIO_PIN_HIGH);
	}
	if(counter == OvflowTime)
	{
		DIO_SetPinValue(GPIO_PORTF,GPIO_PIN1,GPIO_PIN_LOW);
		counter=0;
	}
	
}