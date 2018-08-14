#include <Arduino.h>
#include <Bounce2.h>

//#define USE_MODEL_NODEMCU32
#define USE_MODEL_TTGOV2

#ifdef USE_MODEL_NODEMCU32
  #define PIN_LOCK_MOTOR GPIO_NUM_14
  #define PIN_LOCK_ROTATION_SWITCH GPIO_NUM_12 // (PULLUP!)  LOW: default, HIGH: motor presses against (rotation complete)
  #define PIN_LOCK_LATCH_SWITCH GPIO_NUM_13 // (PULLUP!) LOW: closed, HIGH: open
#endif
#ifdef USE_MODEL_TTGOV2
  #define PIN_LOCK_MOTOR GPIO_NUM_15
  #define PIN_LOCK_ROTATION_SWITCH GPIO_NUM_2 // (PULLUP!)  LOW: default, HIGH: motor presses against (rotation complete)
  #define PIN_LOCK_LATCH_SWITCH GPIO_NUM_4 // (PULLUP!) LOW: closed, HIGH: open
#endif

bool firstBoot = true;

Bounce debounceRotationSwitch = Bounce();
Bounce debounceLatchSwitch = Bounce();

bool shouldRotate = false;

void setup() {
  Serial.begin(115200);

  pinMode(PIN_LOCK_LATCH_SWITCH, INPUT_PULLUP);
  pinMode(PIN_LOCK_ROTATION_SWITCH, INPUT_PULLUP);
  pinMode(PIN_LOCK_MOTOR, OUTPUT);

  debounceRotationSwitch.attach(PIN_LOCK_ROTATION_SWITCH);
  debounceRotationSwitch.interval(5);

  debounceLatchSwitch.attach(PIN_LOCK_LATCH_SWITCH);
  debounceLatchSwitch.interval(5);

  Serial.println('msg="hello world" version=0.0.1');
}

void loop() {
  debounceRotationSwitch.update();
  debounceLatchSwitch.update();

  if (debounceRotationSwitch.read() == HIGH) {
    shouldRotate = false;
  }

  if (debounceLatchSwitch.read() == LOW) {
    shouldRotate = true;
  }

  if (firstBoot || millis() % 1000 == 0) {
    firstBoot = false;
    float sec = (float) millis() / 1000.0;
    Serial.printf("time=%.3f rotation=%d latch=%d shouldRotate=%d\n",
      sec,
      debounceRotationSwitch.read(),
      debounceLatchSwitch.read(),
      shouldRotate);
  }

  if (shouldRotate) {
    digitalWrite(PIN_LOCK_MOTOR, HIGH);
  } else {
    digitalWrite(PIN_LOCK_MOTOR, LOW);
  }
}
