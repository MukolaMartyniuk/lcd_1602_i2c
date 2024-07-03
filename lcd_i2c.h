#ifndef LCD_I2C_H_
#define LCD_I2C_H_

#include "stm32f4xx_hal.h"

#define LCD_I2C_ADDR 0x27

void lcd_i2c_init(I2C_HandleTypeDef *hi2c);

void lcd_i2c_send_command(I2C_HandleTypeDef *hi2c, uint8_t command);

void lcd_i2c_send_data(I2C_HandleTypeDef *hi2c, uint8_t data);

void lcd_i2c_set_cursor(I2C_HandleTypeDef *hi2c, uint8_t row, uint8_t col);

void lcd_i2c_send_string(I2C_HandleTypeDef *hi2c, const char *str);

#endif /* LCD_I2C_H_ */
