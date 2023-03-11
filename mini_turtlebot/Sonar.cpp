#include "Sonar.h"
#include <Arduino.h>

Sonar::Sonar() {};

void Sonar::setup(int trigger_pin, int echo_pin, void (*echo_start_isr)(), void (*echo_end_isr)(), int timeout_cm) {
    this->trigger_pin = trigger_pin;
    this->echo_pin = echo_pin;
    this->timeout_us = (Sonar::SPEED_OF_SOUND_cm_per_us * 2.0) * timeout_cm;
    this->echo_start_isr = echo_start_isr;
    this->echo_end_isr = echo_end_isr;
    this->state = Sonar::IDLE;

    pinMode(this->trigger_pin, OUTPUT);
    pinMode(this->echo_pin, INPUT);
}

Sonar::State Sonar::update() {

  switch(this->state) {
    case Sonar::TRIGGER:
      if (Sonar::delta_us(this->trigger_start_us) > 12) {
        digitalWrite(this->trigger_pin, LOW);
        this->state = Sonar::WAIT_FOR_ECHO;
      }
      break;
    
    case Sonar::WAIT_FOR_ECHO:
      if (Sonar::delta_us(this->trigger_start_us) > this->timeout_us) {
        detachInterrupt(digitalPinToInterrupt(this->echo_pin));
        this->state = Sonar::IDLE;
      }
      break;

    default:
      break;
  }
  return this->state;
}

uint32_t Sonar::read_us() {
  if (this->state == Sonar::READY) {
    this->state = Sonar::IDLE;
    return this->echo_pulse_us;
  } else return 0;
}

uint16_t Sonar::read_cm() {
  return Sonar::pulse_to_cm(this->read_us());
}

void Sonar::trigger() {
  if (this->state == Sonar::IDLE || this->state == Sonar::READY) {
    digitalWrite(this->trigger_pin, HIGH);
    this->trigger_start_us = micros();
    this->state = Sonar::TRIGGER;
    attachInterrupt(digitalPinToInterrupt(this->echo_pin), this->echo_start_isr, RISING);
  }
}

void Sonar::echo_start(){
  this->echo_start_us = micros();
  detachInterrupt(digitalPinToInterrupt(this->echo_pin));
  attachInterrupt(digitalPinToInterrupt(this->echo_pin), this->echo_end_isr, FALLING);
  this->state = Sonar::ECHO;
}

void Sonar::echo_end(){
  this->echo_pulse_us = Sonar::delta_us(this->echo_start_us);
  detachInterrupt(digitalPinToInterrupt(this->echo_pin));
  this->state = Sonar::READY;
}

uint16_t Sonar::pulse_to_cm(uint32_t duration_us) {
  return ((Sonar::SPEED_OF_SOUND_cm_per_us / 2.0) *  duration_us);
}

uint32_t Sonar::delta_us(uint32_t start_us) {
  uint32_t end_us = micros();
  if(end_us >= start_us) return end_us - start_us;
  else { //overflow
    return UINT32_MAX - (start_us - end_us);
  }
}