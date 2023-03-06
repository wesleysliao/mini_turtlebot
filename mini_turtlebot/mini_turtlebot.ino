
#include "wesliao_mtb_struct.h"
#include "wesliao_mtb_servo.h"


void setup() {
  mtb_servo_setup();
}

void loop() {

  mtb.st.servo.left_wheel.write(15);
  mtb.st.servo.right_wheel.write(165);
  delay(1000);

  mtb.st.servo.left_wheel.write(165);
  mtb.st.servo.right_wheel.write(15);
  delay(1000);
}
