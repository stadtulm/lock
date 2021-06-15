#ifndef _lock_globals_h
#define _lock_globals_h

// overriding with our own, https://brandur.org/logfmt compatible log format:
#ifdef ARDUHAL_LOG_FORMAT
#undef ARDUHAL_LOG_FORMAT
#define ARDUHAL_LOG_FORMAT(letter, format)                                     \
  ARDUHAL_LOG_COLOR_##letter                                                   \
      "time=%d level=" #letter                                                 \
      " file=%s line=%u method=%s " format ARDUHAL_LOG_RESET_COLOR "\r\n",     \
      hal_ticks(), pathToFileName(__FILE__), __LINE__, __FUNCTION__
#endif

#define VEXT_ON_PIN 25

#include "lorawan.h"

extern QueueHandle_t wifiQueue;
extern QueueHandle_t gpsQueue;
extern QueueHandle_t taskQueue;
static const int TASK_UNLOCK = 1;
static const int TASK_RESTART = 2;
static const int TASK_SEND_LOCK_STATUS = 3;
static const int TASK_SEND_LOCATION_WIFI = 4;
static const int TASK_SEND_LOCATION_GPS = 5;

static const int LOCK_TASK_UNLOCK = 1;
static const int LOCK_TASK_PARK = 2;
static const int LOCK_TASK_SEND_STATUS = 3;
static const int LOCK_TASK_GPIO_ISR = 4;

#endif // _lock_globals_h
