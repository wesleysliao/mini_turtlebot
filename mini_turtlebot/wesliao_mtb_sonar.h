#include "Sonar.h"

void sonar_forward_echo_start() {  
  mtb.st.sonar.forward.echo_start();
}

void sonar_forward_echo_end() {
  mtb.st.sonar.forward.echo_end();
}


void mtb_sonar_setup() {
  mtb.st.sonar.forward.setup(mtb.cfg.sonar.forward.pin.trigger,
                             mtb.cfg.sonar.forward.pin.echo,
                             sonar_forward_echo_start,
                             sonar_forward_echo_end,
                             mtb.cfg.sonar.forward.max_range_cm);
}