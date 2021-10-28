#ifndef __EC_SysTick_H
#define __EC_SysTick_H

#include "stm32f411xe.h"

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */

void SysTick_init();
void delay_ms(uint32_t msec);
uint32_t SysTick_val(void);
void SysTick_reset(void);
void SysTick_enable(void);
void SysTick_disable (void);
void SysTick_Handler(void);



#ifdef __cplusplus
}
#endif /* __cplusplus */
	 
#endif