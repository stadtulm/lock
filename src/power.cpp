#include "power.h"

static const char *TAG = "power";

uint8_t vext_tasks_count = 0;
void (*vext_on_enable_callback)() = NULL;
void (*vext_on_disable_callback)() = NULL;

bool battery_pin_setup = false;

void use_vext() {
  vext_tasks_count++;
  if (vext_tasks_count == 1) {
    ESP_LOGD(TAG, "enable Vext");
    if (vext_on_enable_callback != NULL)
      vext_on_enable_callback();
    digitalWrite(VEXT_ON_PIN, LOW);
  }
}

void use_vext_end() {
  vext_tasks_count--;
  if (vext_tasks_count == 0) {
    ESP_LOGD(TAG, "disable Vext");
    if (vext_on_disable_callback != NULL)
      vext_on_disable_callback();
    digitalWrite(VEXT_ON_PIN, HIGH);
  }
}