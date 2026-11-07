/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.h
  * @brief          : Header for main.c file.
  *                   This file contains the common defines of the application.
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2026 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef __MAIN_H
#define __MAIN_H

#ifdef __cplusplus
extern "C" {
#endif

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx_hal.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */

/* USER CODE END Includes */

/* Exported types ------------------------------------------------------------*/
/* USER CODE BEGIN ET */

/* USER CODE END ET */

/* Exported constants --------------------------------------------------------*/
/* USER CODE BEGIN EC */

/* USER CODE END EC */

/* Exported macro ------------------------------------------------------------*/
/* USER CODE BEGIN EM */

/* USER CODE END EM */

void HAL_TIM_MspPostInit(TIM_HandleTypeDef *htim);

/* Exported functions prototypes ---------------------------------------------*/
void Error_Handler(void);

/* USER CODE BEGIN EFP */

/* USER CODE END EFP */

/* Private defines -----------------------------------------------------------*/
#define digit_selection_bit0_Pin GPIO_PIN_0
#define digit_selection_bit0_GPIO_Port GPIOC
#define digit_selection_bit1_Pin GPIO_PIN_2
#define digit_selection_bit1_GPIO_Port GPIOC
#define button_count_Pin GPIO_PIN_2
#define button_count_GPIO_Port GPIOA
#define button_count_EXTI_IRQn EXTI2_IRQn
#define buzzer_Pin GPIO_PIN_3
#define buzzer_GPIO_Port GPIOA
#define button_reset_Pin GPIO_PIN_4
#define button_reset_GPIO_Port GPIOA
#define button_reset_EXTI_IRQn EXTI4_IRQn
#define segment_b_Pin GPIO_PIN_8
#define segment_b_GPIO_Port GPIOD
#define segment_d_Pin GPIO_PIN_9
#define segment_d_GPIO_Port GPIOD
#define dot_Pin GPIO_PIN_10
#define dot_GPIO_Port GPIOD
#define segment_c_Pin GPIO_PIN_11
#define segment_c_GPIO_Port GPIOD
#define segment_g_Pin GPIO_PIN_12
#define segment_g_GPIO_Port GPIOD
#define segment_e_Pin GPIO_PIN_13
#define segment_e_GPIO_Port GPIOD
#define segment_a_Pin GPIO_PIN_14
#define segment_a_GPIO_Port GPIOD
#define segment_f_Pin GPIO_PIN_15
#define segment_f_GPIO_Port GPIOD

/* USER CODE BEGIN Private defines */

/* USER CODE END Private defines */

#ifdef __cplusplus
}
#endif

#endif /* __MAIN_H */
