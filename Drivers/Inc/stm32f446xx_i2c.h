#ifndef INC_STM32F446XX_I2C_H_
#define INC_STM32F446XX_I2C_H_

typedef enum {

} I2C_speed;

typedef enum {
	I2C_AUTO_ACK,
	I2C_NO_AUTO_ACK,
} I2C_ack;

typedef struct {

} I2C_init_t;

void I2C_init();
void I2C_transmit_as_master();
void I2C_receive_as_master();
void I2C_transmit_as_slave();
void I2C_receive_as_slave();


#endif
