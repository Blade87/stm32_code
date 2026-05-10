/* main.c */

/******************** Library *********************/
#include "stm32f4xx_hal.h"
#include "main.h"

/******************** Prototype *******************/
void SystemClockConfig(void);
void UART2_Init(void);
void Error_handler(void);

/******************** Handle **********************/
UART_HandleTypeDef huart2;

/******************************************************************************
 * @fn      main
 * @brief
 */
int main(void)
{
	HAL_Init(); /* calls HAL_MspInit(); */
	SystemClockConfig();
	UART2_Init();

	return 0;
}

/******************************************************************************
 * @fn     SystemClockConfig
 * @brief
 */
void SystemClockConfig(void)
{

}

/******************************************************************************
 * @fn     UART2_Init
 * @brief
 */
void UART2_Init(void)
{
	huart2.Instance = USART2;
	huart2.Init.BaudRate = 115200;
	huart2.Init.WordLength = UART_WORDLENGTH_8B;
	huart2.Init.StopBits = UART_STOPBITS_1;
	huart2.Init.Parity = UART_PARITY_NONE;
	huart2.Init.HwFlowCtl = UART_HWCONTROL_NONE;
	huart2.Init.Mode = UART_MODE_TX_RX;

	if (HAL_OK != HAL_UART_Init(&huart2))
	{
		/* Error occured */
		Error_handler();
	}
}

/******************************************************************************
 * @fn     Error_handler
 * @brief
 */
void Error_handler(void)
{
	while(1);
}
