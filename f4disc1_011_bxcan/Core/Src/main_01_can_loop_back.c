/****************** Library **********************/
#include "alt_main.h"

#include "can.h"
/****************** Macro ************************/
#define CAN_MESSAGE_LENGTH 8
/****************** Variable *********************/

/**************************************************
 * @fn       - alt_main
 * @brief    -
**************************************************/
int alt_main()
{
	CAN_TxHeaderTypeDef can_tx_header;
	can_tx_header.IDE   = CAN_ID_STD;
	can_tx_header.StdId = 0x65D;
	can_tx_header.RTR   = CAN_RTR_DATA;
	can_tx_header.DLC   = CAN_MESSAGE_LENGTH;

	uint8_t can_message[CAN_MESSAGE_LENGTH] = {'H', 'E', 'L', 'L', 'o', '0', '0', '2'};

	uint32_t can_tx_mailbox;

	HAL_CAN_Start(&hcan1);
	/**************** Infinite Loop **************/
	while(1)
	{
		if (HAL_CAN_AddTxMessage(&hcan1, &can_tx_header, can_message, &can_tx_mailbox) != HAL_OK)
		{
			Error_Handler();
		}
		while (HAL_CAN_IsTxMessagePending(&hcan1, can_tx_mailbox));
		uint8_t f_successful = 1;
		HAL_Delay(1000);
	}

}
/**************************************************
 * @fn       -
 * @brief    -
**************************************************/
