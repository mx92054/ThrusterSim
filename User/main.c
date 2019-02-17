#include "stm32f10x.h"
#include <math.h>

#include "..\bsp\bsp_led.h"
#include "..\bsp\SysTick.h"
#include "..\bsp\bsp_exti.h"
#include "..\bsp\bsp_innerflash.h"
#include "..\bsp\adc.h"

#include "modbus_svr.h"
#include "Thruster0.h"

//--------------------------------------------------------------------------------
int main(void)
{
	u32 curTick , lastTick = 0 ;

	SysTick_Init();

	LED_GPIO_Config();
	Modbus_init();

	Thruster0_initialize() ;

	InternalFlashRead(wReg, 200);
	BOOTNUM++; // 启动次数加1
	bSaved = 1;

	SetTimer(1, 100);
	SetTimer(2, 500);
	SetTimer(3, 1000);

	IWDG_Configuration();
	LED1_ON;
	while (1)
	{
		Modbus_task();

		if ( GetTimer(1))
		{
			LED1_TOGGLE;

			rtU.Direction = wReg[10] ;
			rtU.Switch = wReg[11] ;
			rtU.Value = wReg[12] ;

			Thruster0_step() ;

			wReg[13] = rtY.Speed ;
		}

		//------------------------------------------------------------------
		if (GetTimer(2))
		{
			curTick = GetCurTick() ;
			wReg[103] = curTick - lastTick ;
			lastTick = curTick;	
			IWDG_Feed();
		}

		if (GetTimer(3) && bSaved)
		{
			curTick = GetCurTick() ;
			InternalFlashWrite(wReg, 200);
			wReg[104] = GetCurTick() - curTick ;
			wReg[105]++ ;
			bSaved = 0;
		}
	}
}

