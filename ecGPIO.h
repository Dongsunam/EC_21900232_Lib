// Distributed for LAB: GPIO

#include "stm32f411xe.h"
#include "ecRCC.h"

#ifndef __ECGPIO_H
#define __ECGPIO_H

#define INPUT  0x00
#define OUTPUT 0x01
#define AF     0x02
#define ANALOG 0x03

#define lowspeed 0
#define mediumspeed 1
#define fastspeed 2
#define highspeed 3

#define HIGH 1
#define LOW  0

#define LED_PIN 	5
#define BUTTON_PIN 13

#define pushpull 0
#define opendrain 1

#define pullup 1
#define pulldown 2
#define nopupd 0

#define segement_a 6
#define segement_b 7
#define segement_c 7
#define segement_d 9
#define segement_e 8
#define segement_f 10
#define segement_g 1

#define MCU_CLK_PLL 84000000
#define MCU_CLK_HSI 16000000

#ifdef __cplusplus
 extern "C" {
#endif /* __cplusplus */
	 
void GPIO_init(GPIO_TypeDef *Port, int pin, int mode);
void GPIO_mode(GPIO_TypeDef* Port, int pin, int mode);


void GPIO_write(GPIO_TypeDef *Port, int pin, int Output);
int  GPIO_read(GPIO_TypeDef *Port, int pin);
void GPIO_ospeed(GPIO_TypeDef* Port, int pin, int speed);
void GPIO_otype(GPIO_TypeDef* Port, int pin, int type);
void GPIO_pudr(GPIO_TypeDef* Port, int pin, int pudr);

void LED_init(void);
void LED_toggle(void);
	
//7segement
void sevensegment_init(void);
void sevensegment_decoder(unsigned int num);




 
#ifdef __cplusplus
}
#endif /* __cplusplus */

#endif
