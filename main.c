#include "stm32f4xx_hal.h"
#include "stdio.h"
#include "lcd_i2c.h"

void I2C1_GPIO_Init(void);

void I2C1_Init(void);

static I2C_HandleTypeDef hi2c1;

int main(void)
{
  HAL_Init();

  I2C1_GPIO_Init();

  I2C1_Init();

  lcd_i2c_init(&hi2c1);

  lcd_i2c_send_string(&hi2c1, "Hello");
  HAL_Delay(1000);
  lcd_i2c_set_cursor(&hi2c1, 1, 0);
  lcd_i2c_send_string(&hi2c1, "world");

  while (1)
  {
  }
}

void SysTick_Handler(void)
{
  HAL_IncTick();
}

void I2C1_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  __HAL_RCC_GPIOB_CLK_ENABLE();

  GPIO_InitStruct.Pin = GPIO_PIN_6 | GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_AF_OD;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  GPIO_InitStruct.Alternate = GPIO_AF4_I2C1;
  GPIO_InitStruct.Pull = GPIO_PULLUP;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);
}

void I2C1_Init(void)
{
  hi2c1.Instance = I2C1;
  hi2c1.Init.ClockSpeed = 100000;
  hi2c1.Init.DutyCycle = I2C_DUTYCYCLE_2;
  hi2c1.Init.OwnAddress1 = 0;
  hi2c1.Init.AddressingMode = I2C_ADDRESSINGMODE_7BIT;
  hi2c1.Init.DualAddressMode = I2C_DUALADDRESS_DISABLE;
  hi2c1.Init.OwnAddress2 = 0;
  hi2c1.Init.GeneralCallMode = I2C_GENERALCALL_DISABLE;
  hi2c1.Init.NoStretchMode = I2C_NOSTRETCH_DISABLE;

  __HAL_RCC_I2C1_CLK_ENABLE();
  if (HAL_I2C_Init(&hi2c1) != HAL_OK)
  {
  }
}