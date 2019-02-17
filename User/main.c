#include "stm32f10x.h"
#include <math.h>

#include "..\bsp\bsp_led.h"
#include "..\bsp\SysTick.h"
#include "..\bsp\bsp_exti.h"
#include "..\bsp\bsp_innerflash.h"
#include "..\bsp\adc.h"

#include "modbus_svr.h"

//--------------------------------------------------------------------------------
int main(void)
{
	u32 curTick , lastTick = 0 ;

	SysTick_Init();

	LED_GPIO_Config();
	Modbus_init();

	InternalFlashRead(wReg, 200);
	BOOTNUM++; // 启动次数加1
	bSaved = 1;

	SetTimer(1, 200);
	SetTimer(2, 500);
	SetTimer(3, 1000);

	IWDG_Configuration();
	LED1_ON;
	while (1)
	{
		Modbus_task();

		//------------------------------------------------------------------
		if (GetTimer(2))
		{
			curTick = GetCurTick() ;
			wReg[103] = curTick - lastTick ;
			lastTick = curTick;	
			LED1_TOGGLE;
			IWDG_Feed();

		}

		if (GetTimer(3) && bSaved)
		{
			InternalFlashWrite(wReg, 200);
			bSaved = 0;
		}
	}
}

