#include <stdint.h>

#include "stm32f446xx.h"
#include "stm32f446xx_gpio.h"

int main(void) {
	GPIO_enable_clock(GPIOC);
	GPIO_enable_clock(GPIOA);
	
	/* On Board Push Button, PC13 */
	GPIO_init(GPIOC, &(GPIO_init_t){
		.GPIO_pin_number = GPIO_PIN_13,
		.GPIO_pin_mode = GPIO_EXTI_IT_FALLING,
		.GPIO_pin_speed = GPIO_HIGH_SPEED,
		.GPIO_pin_output_type = GPIO_PUSH_PULL,
		.GPIO_pin_pull = GPIO_PULL_DOWN,
		.GPIO_pin_alt_function = 0
	});

	GPIO_init(GPIOA, &(GPIO_init_t){
		.GPIO_pin_number = GPIO_PIN_5,
		.GPIO_pin_mode = GPIO_OUTPUT,
		.GPIO_pin_speed = GPIO_HIGH_SPEED,
		.GPIO_pin_output_type = GPIO_PUSH_PULL,
		.GPIO_pin_pull = GPIO_PULL_DOWN,
		.GPIO_pin_alt_function = 0
	});

	NVIC_enable_IRQ(IRQ_EXTI15_10); // pin 5 delivers on EXTI 5

	while(1) {

	}

	return 0;
}

void EXTI15_10_IRQHandler(void) {
	GPIO_handle_IRQ(13);
	GPIO_write_pin(GPIOA, 5, 1);
}
