/********************************************************************************
* @author  Dongsu Nam
* @Mod		 2021-8-12 by YKKIM  	
* @brief   Embedded Controller:  LAB Digital In/Out
*					 - Toggle LED LD2 by Button B1  pressing
* 
******************************************************************************
*/
#include "stm32f4xx.h"
#include "ecGPIO.h"
#include "ecRCC.h"

#define LED_PIN 	5
#define BUTTON_PIN 13
void setup(void);
	
int main(void) { 
	int flag1_1 = 1;
	int flag1_2 = 0;
	
	int flag2_1 = 0;
	int flag2_2 = 0;
	setup();

	while(1){
			if(GPIO_read(GPIOC, BUTTON_PIN)==0){
				if(flag1_1 != 0){
					GPIO_write(GPIOA, LED_PIN, HIGH);
					flag2_1 += 1;
					flag2_2 = 0;
				}
				if(flag1_2 != 0){
					GPIO_write(GPIOA, LED_PIN, LOW);
					flag2_1 = 0;
					flag2_2 += 1;
				}
			}
			else{
				if(flag2_1 != 0){
					GPIO_write(GPIOA, LED_PIN, HIGH);
					flag1_2 += 1;
					flag1_1 = 0;
				}
				if(flag2_2 != 0){
					GPIO_write(GPIOA, LED_PIN, LOW);
					flag1_1 += 1;
					flag1_2 = 0;
				}
			}
	}
}

void setup(void)
{
	RCC_HSI_init();	
	GPIO_init(GPIOC, BUTTON_PIN, INPUT);  // calls RCC_GPIOC_enable()
	GPIO_init(GPIOA, LED_PIN, OUTPUT);    // calls RCC_GPIOA_enable()	
}
