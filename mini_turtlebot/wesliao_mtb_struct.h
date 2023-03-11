#include <ESP32Servo.h>
#include "Sonar.h"

struct ServoConfig {
  uint8_t pin;
  uint16_t pulse_min_us;
  uint16_t pulse_max_us;
};

struct SonarConfig {
  struct {
    uint8_t trigger;
    uint8_t echo;
  } pin;
  uint16_t max_range_cm;
};

struct MiniTurtleBotConfig {
  const struct {
    const ServoConfig left_wheel = {.pin = 32, 
                                    .pulse_min_us=500, 
                                    .pulse_max_us=2400};
    const ServoConfig right_wheel = {.pin = 33, 
                                     .pulse_min_us=500, 
                                     .pulse_max_us=2400};
  } servo;

  const struct {
    const SonarConfig forward = {.pin = {.trigger = 12,
                                         .echo = 13},
                                 .max_range_cm = 200};
  } sonar;
};

struct MiniTurtleBotState {
  struct {
    Servo left_wheel;
    Servo right_wheel;
  } servo;

  struct {
    Sonar forward;
  } sonar;
};

struct MiniTurtleBot {
  MiniTurtleBotConfig cfg;
  MiniTurtleBotState st;
} mtb;