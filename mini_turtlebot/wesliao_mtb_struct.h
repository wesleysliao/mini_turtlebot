#include <ESP32Servo.h>

struct ServoConfig {
  uint8_t pin;
  uint16_t pulse_min_us;
  uint16_t pulse_max_us;
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
};

struct MiniTurtleBotState {
  struct {
    Servo left_wheel;
    Servo right_wheel;
  } servo;
};

struct MiniTurtleBot {
  MiniTurtleBotConfig cfg;
  MiniTurtleBotState st;
} mtb;