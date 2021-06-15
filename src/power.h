/**
 ******************************************************************************
 * @file    src/power.h
 * @brief   Header for power.c module
 ******************************************************************************
 */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef _lock_power_h
#define _lock_power_h

/* Includes ------------------------------------------------------------------*/
#include <Arduino.h>
#include "globals.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
extern uint8_t vext_tasks_count;
extern void (*vext_on_enable_callback)();
extern void (*vext_on_disable_callback)();

/* Exported macro ------------------------------------------------------------*/
#define BATTERY_VOLTAGE_PIN 32

/* Exported functions ------------------------------------------------------- */
void use_vext();
void use_vext_end();

#endif // _lock_power_h