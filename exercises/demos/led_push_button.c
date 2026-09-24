#include <stdint.h>

#include "stm32f446xx.h"
#include "stm32f446xx_gpio.h"

#define LED PA5
#define BUTTON PC13

int
main(void) {
  GPIO_init_t* onboard_led = &(GPIO_init_t) {
    .GPIO_pin_number = GPIO_PIN_5,
    .GPIO_pin_mode = GPIO_OUTPUT,
    .GPIO_pin_output_type = GPIO_PUSH_PULL,
    .GPIO_pin_pull = GPIO_NO_PULL,
    .GPIO_pin_speed = GPIO_HIGH_SPEED,
  };

  GPIO_init_t* push_button = &(GPIO_init_t) {
    .GPIO_pin_number = GPIO_PIN_13,
    .GPIO_pin_mode = GPIO_INPUT,
    .GPIO_pin_output_type = GPIO_OPEN_DRAIN,
    .GPIO_pin_pull = GPIO_NO_PULL,
    .GPIO_pin_speed = GPIO_HIGH_SPEED,
  };


	GPIO_enable_clock(GPIOA);
	GPIO_enable_clock(GPIOB);

  GPIO_init(GPIOA, onboard_led);
  GPIO_init(GPIOC, push_button);

  while(1) {
    volatile uint8_t button_pushed = !GPIO_read_pin(GPIOC, BUTTON);

    GPIO_write_pin(GPIOA, LED, button_pushed);
  }

  return 0;
}
