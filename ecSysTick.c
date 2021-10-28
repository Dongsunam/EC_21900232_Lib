#include "stm32f4xx.h"
#include "ecRCC.h"
#include "ecGPIO.h"
#include "ecEXTI.h"
#include "ecSysTick.h"


volatile uint32_t msTick = 0;
volatile uint32_t curTicks;

void SysTick_init(uint32_t msec){
   SysTick_disable ();                         

   SysTick->CTRL |= 1UL<<2U;
   SysTick->LOAD = (MCU_CLK_PLL/msec); 
   SysTick->VAL = 0;
   SysTick->CTRL |= 1UL<<1U;
   
   SysTick_enable();
   
   NVIC_SetPriority(SysTick_IRQn, 1);  
   NVIC_EnableIRQ(SysTick_IRQn);
}

void delay_ms(uint32_t msec){
   curTicks = msTick;
   while((msTick-curTicks)<msec);
   msTick=0;
}

uint32_t SysTick_val(void){
   return SysTick->VAL;
}

void SysTick_reset (void){
   SysTick->VAL = 0;
}

void SysTick_enable(void){
   SysTick->CTRL |= 1UL<<0U;      
}

void SysTick_disable (void){
   SysTick->CTRL = 0;
}

void SysTick_Handler(void){
   msTick++;
}
