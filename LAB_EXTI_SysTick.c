/********************************************************************************
* @author  Dongsu Nam
* @Mod		 2021-8-30 by YKKIM  	
* @brief   Embedded Controller:  LAB Systick&EXTI with API
*					 - 7 segment
* 
*******************************************************************************/

#include "stm32f4xx.h"
#include "ecGPIO.h"
#include "ecRCC.h"
#include "ecSysTick.h"

void setup(void);
// Initialiization 

int main(void) { 
	int count= 0;
	// Initialiization --------------------------------------------------------
	setup();
	// Inifinite Loop ----------------------------------------------------------
	while(1){
		sevensegment_decoder(count%10);
		delay_ms(1000);
		count++;
		SysTick_reset();
	}
}

	
void setup(void){
	RCC_PLL_init();
	SysTick_init(1000);
	sevensegment_init();
}