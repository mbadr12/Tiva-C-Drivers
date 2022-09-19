/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H
/******************************************** System Control Registers  **********************************************/

#define SC_BASE_ADDRESS							0x400FE000UL

#define SC_GPIOHBCTL							*((volatile uint32*)(SC_BASE_ADDRESS+0x06c))

#define RC_RCGCGPIO								*((volatile uint32*)(SC_BASE_ADDRESS+0x608))

#define SC_RCGCWD								*((volatile uint32*)(SC_BASE_ADDRESS+0x600))

/******************************************** NVIC Peripheral Definition *********************************************/

#define NVIC_BASE_ADDRESS						0xE000E100UL
#define SCB_BASE_ADDRESS						0xE000E000UL

/******************************************** NVIC Registers Definition **********************************************/

typedef struct
{
	volatile uint32 EN[5];
	uint32 Reserved[27];
	volatile uint32 DIS[5];
	uint32 Reserved1[27];
	volatile uint32 PEND[5];
	uint32 Reserved2[27];
	volatile uint32 UNPEND[5];
	uint32 Reserved3[27];
	volatile uint32 ACTIVE[5];
	uint32 Reserved4[59];
	volatile uint8 PRI[138];
}NVIC_RegDef_t;

#define NVIC								((NVIC_RegDef_t*)NVIC_BASE_ADDRESS)

#define SCB_APINT							*((volatile uint32*) (SCB_BASE_ADDRESS+0xD0C))

/******************************************** GPIO Peripheral Definition *********************************************/

#define GPIOA_BASE_ADDRESS					0x40004000UL
#define GPIOB_BASE_ADDRESS					0x40005000UL
#define GPIOC_BASE_ADDRESS					0x40006000UL
#define GPIOD_BASE_ADDRESS					0x40007000UL
#define GPIOE_BASE_ADDRESS					0x40024000UL
#define GPIOF_BASE_ADDRESS					0x40025000UL


/******************************************** GPIO Registers Definition **********************************************/
typedef struct
{
	volatile uint32 GPIODATA[256];           /*GPIO Data*/                 
	volatile uint32 GPIODIR;                 /*GPIO Direction*/
	volatile uint32 GPIOIS;                  /*GPIO Interrupt Sense*/
	volatile uint32 GPIOIBE;                 /*GPIO Interrupt Both Edges*/
	volatile uint32 GPIOIEV;                 /*GPIO Interrupt Event*/
	volatile uint32 GPIOIM;                  /*GPIO Interrupt Mask*/
	volatile uint32 GPIORIS;                 /*GPIO Raw Interrupt Status*/
	volatile uint32 GPIOMIS;                 /*GPIO Masked Interrupt Status*/
	volatile uint32 GPIOICR;                 /*GPIO GPIO Interrupt Clear*/
	volatile uint32 GPIOAFSEL;               /*GPIO Alternate Function Select*/
	uint32 Reserved[55];                    
	volatile uint32 GPIODR2R;                /*GPIO 2-mA Drive Select*/
	volatile uint32 GPIODR4R;                /*GPIO 4-mA Drive Select*/
	volatile uint32 GPIODR8R;                /*GPIO 8-mA Drive Select*/
	volatile uint32 GPIOODR;                 /*GPIO Open Drain Select*/
	volatile uint32 GPIOPUR;                 /*GPIO Pull-Up Select*/
	volatile uint32 GPIOPDR;                 /*GPIO Pull-Down Select*/
	volatile uint32 GPIOSLR;                 /*GPIO Slew Rate Control Select*/
	volatile uint32 GPIODEN;                 /*GPIO Digital Enable*/
	volatile uint32 GPIOLOCK;                /*GPIO Lock*/
	volatile uint32 GPIOCR;                  /*GPIO Commit*/
	volatile uint32 GPIOAMSEL;               /*GPIO Analog Mode Select*/
	volatile uint32 GPIOPCTL;                /*GPIO Port Control*/
	volatile uint32 GPIOADCCTL;              /*GPIO ADC Control*/
	volatile uint32 GPIODMACTL;              /*GPIO DMA Control*/
}GPIO_RegDef_t;

#define GPIOA							((GPIO_RegDef_t*) GPIOA_BASE_ADDRESS)
#define GPIOB                           ((GPIO_RegDef_t*) GPIOB_BASE_ADDRESS)
#define GPIOC                           ((GPIO_RegDef_t*) GPIOC_BASE_ADDRESS)
#define GPIOD                           ((GPIO_RegDef_t*) GPIOD_BASE_ADDRESS)
#define GPIOE                           ((GPIO_RegDef_t*) GPIOE_BASE_ADDRESS)
#define GPIOF                           ((GPIO_RegDef_t*) GPIOF_BASE_ADDRESS)


/******************************************** SysTick Peripheral Definition *********************************************/

#define STK_BASE_ADDRESS						0xE000E010UL

/******************************************** SysTick Registers Definition **********************************************/

typedef struct
{
	volatile uint32 STCTRL;						/*SysTick Control and Status Register*/
	volatile uint32 STRELOAD;                   /*SysTick Reload Value Register*/
	volatile uint32 STCURRENT;                  /*SysTick Current Value Register*/
}STK_RegDef_t;

#define STK								((STK_RegDef_t*) STK_BASE_ADDRESS)		

#endif  /* MCU_HW_H */
