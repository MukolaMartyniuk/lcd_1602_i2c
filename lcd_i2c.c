#include "lcd_i2c.h"

void lcd_i2c_init(I2C_HandleTypeDef *hi2c)
{
	HAL_Delay(50);
	lcd_i2c_send_command(hi2c, 0x30);
	HAL_Delay(5);
	lcd_i2c_send_command(hi2c, 0x30);
	HAL_Delay(1);
	lcd_i2c_send_command(hi2c, 0x30);
	HAL_Delay(10);
	lcd_i2c_send_command(hi2c, 0x20);
	HAL_Delay(10);

	lcd_i2c_send_command(hi2c, 0x28);
	HAL_Delay(1);
	lcd_i2c_send_command(hi2c, 0x08);
	HAL_Delay(1);
	lcd_i2c_send_command(hi2c, 0x01);
	HAL_Delay(1);
	HAL_Delay(1);
	lcd_i2c_send_command(hi2c, 0x06);
	HAL_Delay(1);
	lcd_i2c_send_command(hi2c, 0x0C);
}

void lcd_i2c_send_command(I2C_HandleTypeDef *hi2c, uint8_t command)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (command & 0xf0);
	data_l = ((command << 4) & 0xf0);
	data_t[0] = data_u | 0x0C;
	data_t[1] = data_u | 0x08;
	data_t[2] = data_l | 0x0C;
	data_t[3] = data_l | 0x08;
	HAL_I2C_Master_Transmit(hi2c, LCD_I2C_ADDR << 1, (uint8_t *)data_t, 4, 100);
}

void lcd_i2c_send_data(I2C_HandleTypeDef *hi2c, uint8_t data)
{
	char data_u, data_l;
	uint8_t data_t[4];
	data_u = (data & 0xf0);
	data_l = ((data << 4) & 0xf0);
	data_t[0] = data_u | 0x0D;
	data_t[1] = data_u | 0x09;
	data_t[2] = data_l | 0x0D;
	data_t[3] = data_l | 0x09;
	HAL_I2C_Master_Transmit(hi2c, LCD_I2C_ADDR << 1, (uint8_t *)data_t, 4, 100);
}

void lcd_i2c_set_cursor(I2C_HandleTypeDef *hi2c, uint8_t row, uint8_t col)
{
	uint8_t position = (row == 0 ? (0x80 + col) : (0xC0 + col));
	lcd_i2c_send_command(hi2c, position);
}

void lcd_i2c_send_string(I2C_HandleTypeDef *hi2c, const char *str)
{
	while (*str)
	{
		lcd_i2c_send_data(hi2c, (uint8_t)(*str));
		str++;
	}
}
