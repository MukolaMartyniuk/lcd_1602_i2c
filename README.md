# LCD 1602

## DESCRIPTION

Application that allows you to display text on a 1602 or 1602a LCD I2C display. Data transfer is performed using the I2C interface. The master device is the STM32F411E DISCO.

## Hardware requirements
+ LCD1602 I2C or LCD1602A I2C
+ STM32F411E DISCO

## Software requirements
+ Programming language C
+ Keil uVision 5

## Instructions for use
Connect the display outputs to the board pins. SDA output to PB7 pin, SCL to PB6, GND to GND, VCC output to 5V or 3V pins. In Keil uVision, open the lcd_1602_i2c.uvprojx file and run the code.
In function `lcd_i2c_send_string(&hi2c1, "Hello")` you can change the text for display.

## The result of the program
![lcd_1602_i2c](https://github.com/MukolaMartyniuk/lcd_1602_i2c/blob/main/lcd_output.jpg)
