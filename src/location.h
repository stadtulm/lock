/**
 ******************************************************************************
 * @file    src/location.h
 * @brief   Header for location.c module
 ******************************************************************************
 */

/* Define to prevent recursive inclusion
 * ------------------------------------ation*/
#ifndef _lock_location_h
#define _lock_location_h

/* Includes ------------------------------------------------------------------*/
#include <vector>
#include "WiFi.h"

/* Exported types ------------------------------------------------------------*/
/* Exported constants --------------------------------------------------------*/
extern QueueHandle_t wifiQueue;
extern QueueHandle_t gpsQueue;
// wifis which contain this string did
// opt out from location services
static const String nomapSuffix = "_nomap";
static const int maxScanWifis = 7;

static const int GPSRX = 16;
static const int GPSTX = 17;
static const uint32_t GPSBaud = 9600;

/* Exported macro ------------------------------------------------------------*/
/* Exported functions ------------------------------------------------------- */
void wifi_task(void *ignore);
void gps_task(void *ignore);

#endif // _lock_location_h
