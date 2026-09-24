#include <stdint.h>

#include "stm32f446xx.h"
#include "stm32f446xx_gpio.h"

void EXTI15_10_IRQHandler(void) {
	GPIO_handle_IRQ(13);

	if (GPIO_read_pin(GPIOA, 5) & 1) {
		GPIO_write_pin(GPIOA, 5, 0);
	} else {
		GPIO_write_pin(GPIOA, 5, 1);
	}

}


int main(void) {
	GPIO_enable_clock(GPIOC);
	GPIO_enable_clock(GPIOA);
	

	/* On Board Push Button, PC13 */
	GPIO_init(GPIOC, &(GPIO_init_t){
		.GPIO_pin_number = GPIO_PIN_13,
		.GPIO_pin_mode = GPIO_EXTI_IT_RISING_FALLING,
		.GPIO_pin_speed = GPIO_HIGH_SPEED,
		.GPIO_pin_output_type = GPIO_PUSH_PULL,
		.GPIO_pin_pull = GPIO_PULL_UP,
		.GPIO_pin_alt_function = 0
	});

	GPIO_init(GPIOA, &(GPIO_init_t){
		.GPIO_pin_number = GPIO_PIN_5,
		.GPIO_pin_mode = GPIO_OUTPUT,
		.GPIO_pin_speed = GPIO_HIGH_SPEED,
		.GPIO_pin_output_type = GPIO_PUSH_PULL,
		.GPIO_pin_pull = GPIO_NO_PULL,
		.GPIO_pin_alt_function = 0
	});
	GPIO_write_pin(GPIOA, 5, 0);
	NVIC_enable_IRQ(IRQ_EXTI15_10);

	while(1) {

	}

	return 0;
}
/* Done :) */
