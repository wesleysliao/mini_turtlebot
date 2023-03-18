#include "Sonar.h"

void sonar_forward_left_echo_start() {  
  mtb.st.sonar.forward_left.echo_start();
}

void sonar_forward_left_echo_end() {
  mtb.st.sonar.forward_left.echo_end();
}

void sonar_forward_right_echo_start() {  
  mtb.st.sonar.forward_right.echo_start();
}

void sonar_forward_right_echo_end() {
  mtb.st.sonar.forward_right.echo_end();
}


void mtb_sonar_setup() {
  mtb.st.sonar.forward_left.setup(mtb.cfg.sonar.forward_left.pin.trigger,
                                  mtb.cfg.sonar.forward_left.pin.echo,
                                  sonar_forward_left_echo_start,
                                  sonar_forward_left_echo_end,
                                  mtb.cfg.sonar.forward_left.max_range_cm);

  mtb.st.sonar.forward_right.setup(mtb.cfg.sonar.forward_right.pin.trigger,
                                   mtb.cfg.sonar.forward_right.pin.echo,
                                   sonar_forward_right_echo_start,
                                   sonar_forward_right_echo_end,
                                   mtb.cfg.sonar.forward_right.max_range_cm);
}

void mtb_sonar_loop() {

  int left = 0, right = 0;

  switch(mtb.st.sonar.forward_left.update()) {
    case Sonar::IDLE:
      mtb.st.sonar.forward_left.trigger();
      break;
    
    case Sonar::READY:
      left = mtb.st.sonar.forward_left.read_cm();
      break;
  }

  switch(mtb.st.sonar.forward_right.update()) {
    case Sonar::IDLE:
      mtb.st.sonar.forward_right.trigger();
      break;
    
    case Sonar::READY:
      right = mtb.st.sonar.forward_right.read_cm();
      break;
  }

  if(left || right) {
    Serial.print("l ");
    Serial.print(left);
    Serial.print(" - r ");
    Serial.print(right);
    Serial.print("\n");
  }
}