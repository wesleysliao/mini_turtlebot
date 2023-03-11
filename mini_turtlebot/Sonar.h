#ifndef _WESLIAO_TURTLEBOT_SONAR_H_
#define _WESLIAO_TURTLEBOT_SONAR_H_

#include <stdint.h>

class Sonar {
  public:
    Sonar();
    void setup(int trigger_pin, int echo_pin, void (*echo_start_isr)(), void (*echo_end_isr)(), int timeout_cm);
    enum State {
      IDLE, TRIGGER, WAIT_FOR_ECHO, ECHO, READY 
    };
    State update();
    uint16_t read_cm();
    uint32_t read_us();
    void trigger();
    void echo_start();
    void echo_end();
    static uint16_t pulse_to_cm(uint32_t duration_us);
    static uint32_t delta_us(uint32_t start_us);
    constexpr static double SPEED_OF_SOUND_cm_per_us = 0.034300;
  
  protected:
    void (*echo_start_isr)();
    void (*echo_end_isr)();
    uint8_t trigger_pin;
    uint32_t trigger_start_us;
    uint8_t echo_pin;
    uint32_t echo_start_us;
    uint32_t echo_pulse_us;
    uint32_t timeout_us;
    State state;
};

#endif //_WESLIAO_TURTLEBOT_SONAR_H_