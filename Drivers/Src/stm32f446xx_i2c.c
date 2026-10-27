#include "stm32f446xx_i2c.h"

void I2C_init(I2C_t* I2C_interface, I2C_init_t I2C_init) {

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
