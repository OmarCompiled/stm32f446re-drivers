#include "stm32f446xx_i2c.h"

uint8_t ahb_prescalars[8] = [2, 4, 8, 16, 64, 128, 256, 512];
uint32_t get_APB1_clk_speed(void) {
	uint32_t clk_speed = 0;
	uint8_t ahb_prescalar = 0;
	uint8_t apb1_prescalar = 0;
	uint8_t temp = 0;

	temp = ((RCC->CFGR >> 2) & 0x3U);

	switch (temp) {
		case 0:
			clk_speed = 16 * 1000000;
			break;
		case 1:
			clk_speed = 8 * 1000000;
			break;
		case 3: // PLL to be implemented.
			break;
		default:
			break;
	}
	
	temp = ((RCC->CFGR >> 4) & 0xF);
	if (temp < 8) {
		ahb_prescalar = 1;
	} else {
		temp &= 0x7;
		ahb_prescalar = ahb_prescalars[temp];
	}

	temp = ((RCC->CFGR >> 10) & 0x7);
	if (temp < 4) {
		apb1_prescalar = 1;
	} else {
		temp &= 0x3;
		apb1_prescalar = (2 << temp);
	}

	return (clk_speed / ahb_prescalar) / apb1_prescalar;
}

void I2C_init(I2C_t* I2C_interface, I2C_init_t I2C_init) {
	uint32_t temp = 0;

	temp |= (I2C_init->I2C_ack_control << 10);
	I2C_interface->CR1 |= temp;

	temp = get_APB1_clk_speed() / 1000000;
 	if (2 <= temp && temp <= 50) {
		I2C_interface->CR2 |= (temp & 0x2F);
	}	else {
		I2C_interface->CR2 |= 0x2;
	}
}

void I2C_deinit(I2C_t* I2C_interface) {
	if (I2C_interface == I2C1) {
		RCC_I2C1_RESET();
	} else if (I2C_interface == I2C2) {
		RCC_I2C2_RESET();
	} else if (I2C_interface == I2C3) {
		RCC_I2C3_RESET();
	}
	// may or may not add FMPI2C1 later.
}

void I2C_enable_clock(I2C_t* I2C_interface) {
	if (I2C_interface == I2C1) {
		RCC_I2C1_CLK_ENABLE();
	} else if (I2C_interface == I2C2) {
		RCC_I2C2_CLK_ENABLE();
	} else if (I2C_interface == I2C3) {
		RCC_I2C3_CLK_ENABLE();
	}
}

void I2C_disable_clock(I2C_t* I2C_interface) {
	if (I2C_interface == I2C1) {
		RCC_I2C1_CLK_DISABLE();
	} else if (I2C_interface == I2C2) {
		RCC_I2C2_CLK_DISABLE();
	} else if (I2C_interface == I2C3) {
		RCC_I2C3_CLK_DISABLE();
	}
}
