#ifndef INC_STM32F446XX_GPIO_H_
#define INC_STM32F446XX_GPIO_H_

#include <stdint.h>
#include "stm32f446xx.h"
#include "stm32f446xx_gpio_ex.h"

typedef enum {
	GPIO_INPUT,
	GPIO_OUTPUT,
	GPIO_ALT_FUNCTION,
	GPIO_ANALOG,
} GPIO_mode_t;

typedef enum {
	GPIO_PUSH_PULL,
	GPIO_OPEN_DRAIN,
} GPIO_output_type_t;

typedef enum {
	GPIO_LOW_SPEED,
	GPIO_MEDIUM_SPEED,
	GPIO_HIGH_SPEED,
	GPIO_VERY_HIGH_SPEED,
} GPIO_output_speed_t;

typedef enum {
	GPIO_NO_PULL,
	GPIO_PULL_UP,
	GPIO_PULL_DOWN
} GPIO_pull_t;

typedef struct {
	uint16_t			GPIO_pin_number;
	GPIO_mode_t			GPIO_pin_mode;
	GPIO_output_speed_t GPIO_pin_speed;
	GPIO_pull_t 		GPIO_pin_pull;
	GPIO_output_type_t 	GPIO_pin_output_type;
	uint8_t 			GPIO_pin_alt_function;
} GPIO_init_t;

void
GPIO_init(GPIO_t* GPIO_port, GPIO_init_t* pGPIO_init);

void
GPIO_deinit(GPIO_t* GPIO_port);

void
GPIO_clk_control(GPIO_t* GPIO_port, uint8_t enable);

uint8_t
GPIO_read_pin(GPIO_t* GPIO_port, uint8_t pin_number);

uint16_t
GPIO_read_port(GPIO_t* GPIO_port);

void
GPIO_write_pin(GPIO_t* GPIO_port, uint8_t pin_number, uint8_t pin_state);

void
GPIO_write_port(GPIO_t* GPIO_port, uint16_t value);

void
GPIO_irq_config(void);

void
GPIO_irq_handling(void);

#endif
