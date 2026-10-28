#ifndef INC_STM32F446XX_I2C_H_
#define INC_STM32F446XX_I2C_H_

#include "stm32f446xx.h"

// NOTE:
// FM = Fast mode

typedef enum {
	PE,
	SMBUS,
	__RESERVED2__,
	SMBTYPE,
	ENARP,
	ENPEC,
	ENGC,
	NOSTRETCH,
	START,
	STOP,
	ACK,
	POS,
	PEC,
	ALERT,
	__RESERVED14__,
	SWRST
} I2C_CR1_bits;

typedef enum {
	ITERREN = 8,
	ITEVTEN,
	ITBUFEN,
	DMAEN,
	LAST
} I2C_CR2_bits;

//typedef enum {
//
//} I2C_SR1_bits;
//
//typedef enum {
//
//} I2C_SR2_bits;
//
//typedef enum {
//
//} I2C_CCR_bits;
//
//typedef enum {
//
//} I2C_speed;

typedef enum {
	I2C_AUTO_ACK,
	I2C_NO_AUTO_ACK,
} I2C_ack;

typedef struct {
	I2C_speed I2C_SCL_speed;
	uint8_t I2C_device_address;
	uint8_t I2C_ack_control;
	uint16_t I2C_FM_duty_cycle;
} I2C_init_t;

void I2C_init();
void I2C_deinit();
void I2C_enable_clock(I2C_t* I2C_interface);
void I2C_disable_clock(I2C_t* I2C_interface);
void I2C_transmit_as_master();
void I2C_receive_as_master();
void I2C_transmit_as_slave();
void I2C_receive_as_slave();

#endif
