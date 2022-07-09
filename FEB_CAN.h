/*
 * FEB_CAN.h
 *
 *  Created on: Jul 5, 2022
 *      Author: TK
 */

#ifndef FEB_CAN_FEB_CAN_H_
#define FEB_CAN_FEB_CAN_H_

#include "stm32f4xx_hal.h"
#include "FEB_logger.h"

/**
 * @brief Setup CAN filter.
 * 
 * @ref https://schulz-m.github.io/2017/03/23/stm32-can-id-filter/
 * 
 * @param CANx the CAN handler provided by ST HAL library
 * @param filter_id the ID of the filter
 * @param filter_mask the mask of the filter
 */
void FEB_CAN_initFilter(CAN_HandleTypeDef *CANx, uint32_t filter_id, uint32_t filter_mask);

/**
 * @brief Transmit a CAN frame.
 * 
 * @param CANx the CAN handler provided by ST HAL library
 * @param can_id the ID of the CAN frame
 * @param data the pointer to the data, maximum 8 bytes 
 * @param size size of the data, in range 0-8
 * @param is_blocking if true, the function will not return if it failed to transmit the frame
 * @return HAL_StatusTypeDef 
 */
HAL_StatusTypeDef FEB_CAN_transmit(CAN_HandleTypeDef *CANx, uint16_t can_id, uint8_t *data, uint16_t size, uint8_t is_blocking);

#endif /* FEB_CAN_FEB_CAN_H_ */
