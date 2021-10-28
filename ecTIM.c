#include "stm32f411xe.h"
#include "ecTIM.h"
#include "ecGPIO.h"

void TIM_init(TIM_TypeDef *timerx, uint32_t msec){
         
   // 1. Enable Timer Peripheral Clock
   if(timerx == TIM1)            RCC->APB2ENR |= 1UL<<0;
   else if(timerx == TIM2)      RCC->APB1ENR |= 1UL<<0;
   else if(timerx == TIM3)    RCC->APB1ENR |= 1UL<<1;
   else if(timerx == TIM4)      RCC->APB1ENR |= 1UL<<2;
   else if(timerx == TIM5)      RCC->APB1ENR |= 1UL<<3;
   else if(timerx == TIM9)      RCC->APB2ENR |= 1UL<<16;
   else if(timerx == TIM10)   RCC->APB2ENR |= 1UL<<17;
   else if(timerx == TIM11)   RCC->APB2ENR |= 1UL<<18;
   
   // 2. Set Timer Clock Pre-Scaler Value : PRE-SCALER SETTING(PSC)
   timerx->PSC = 84-1; // PLL = 84MHz -> 1Mz
   
   // 3. Set Auto-Reload Value : AUTO-RELOAD SETTING(ARR)
   timerx->ARR = 1000*msec - 1; // Counter Period of 1kHz : 1ms 
   
   // 4. Set Counting Direction : COUNTING DIRECTION SETTING
   timerx->CR1 &= ~(1UL<<4);
   
   // 5. Enable Timer Interrupt : DMA/INTERRUPT (DIER)
   timerx->DIER |= 1UL<<0;
   
   //=============================================================
   // 6. Enable Counter
}


void TIM_period_ms(TIM_TypeDef* timx, uint32_t msec){
   
   uint32_t prescaler = 8400;
   uint16_t ARRval = (84000 / prescaler) * msec;  // 84MHz/1000000 us

   timx->PSC = prescaler - 1;
   timx->ARR = ARRval - 1;
}

void TIM_INT_init(TIM_TypeDef* timerx, uint32_t msec){
   TIM_init(timerx, msec);
   uint32_t TIMx_IRQn = 0;
   
   if(timerx == TIM1)            TIMx_IRQn = 25; // TIM1 Update Interrupt // 27 : TIM1 Capture Compare Interrupt
   else if(timerx == TIM2)      TIMx_IRQn = 28;
   else if(timerx == TIM3)      TIMx_IRQn = 29;
   else if(timerx == TIM4)      TIMx_IRQn = 30;
   else if(timerx == TIM5)      TIMx_IRQn = 50;
   else if(timerx == TIM9)      TIMx_IRQn = 24;
   else if(timerx == TIM11)   TIMx_IRQn   = 26;
   
   // TIM2_IRQn   
   NVIC_EnableIRQ(TIMx_IRQn);
   NVIC_SetPriority(TIMx_IRQn, 2);
   
}


void TIM_period_us(TIM_TypeDef* timx, uint32_t usec){
   // Period usec = 1 to 1000 [1usec ~ 1msec]
   // 1us(1MHz, ARR=1) to 65msec (ARR=0xFFFF)   
   timx->ARR = usec - 1; // input = 1,,,ARR = 0
      
}

void TIM_INT_enable(TIM_TypeDef* timx){
   timx->DIER |= 1UL<<0;
}

void TIM_INT_disable(TIM_TypeDef* timx){
   timx->DIER &= ~(1UL<<0);
}

uint32_t is_UIF(TIM_TypeDef *TIMx){
   return TIMx->SR & (1UL<<0); // Update Interrupt Flag
}

void clear_UIF(TIM_TypeDef *TIMx){
   TIMx->SR &= ~(1UL<<0); // Update Interrupt Flag
}
