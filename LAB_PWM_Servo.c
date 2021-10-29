/********************************************************************************
* @author  Dongsu Nam
* @Mod		 2021-10-22 by NDS 	
* @brief   Embedded Controller: PWM_ServoMotor
* 
*******************************************************************************/


#include "stm32f4xx.h"
#include "ecGPIO.h"
#include "ecRCC.h"
#include "ecTIM.h"
#include "ecPWM.h"
#include "ecSysTick.h"
#include "ecEXTI.h"

PWM_t pwm;

void setup(void);
void EXTI15_10_IRQHandler(void);
void TIM2_IRQHandler(void);

float flag = 0.5;



int main(void){
	setup();
	
	while(1){
	PWM_duty(&pwm, 0.005);
	}
}

void setup(void){
	RCC_PLL_init();
	SysTick_init();
	
	EXTI_init(GPIOC, BUTTON_PIN, FALL, 0);
	GPIO_init(GPIOC, BUTTON_PIN, INPUT);
	GPIO_pudr(GPIOC, BUTTON_PIN, pullup);
	
	GPIO_init(GPIOA, 1, AF);  // AF=2
	GPIO_ospeed(GPIOA, 1, fastspeed);  // speed VHIGH=3
	GPIO_otype(GPIOA, 1, pushpull);
	GPIO_pudr(GPIOA, 1, nopupd);
	
	LED_init();

	TIM_init(TIM2, 1000);
	
	PWM_init(&pwm, GPIOA, 1);
	PWM_period_ms(&pwm, 20);
}

void EXTI15_10_IRQHandler(void) {  
	if (is_pending_EXTI(BUTTON_PIN)) {
		LED_toggle();
		flag += 0.2;
		if (flag > 2.6) flag = 0.5;
		clear_pending_EXTI(BUTTON_PIN); // cleared by writing '1'
	}
}
