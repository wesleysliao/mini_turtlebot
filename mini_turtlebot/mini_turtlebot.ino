
#include "wesliao_mtb_struct.h"
#include "wesliao_mtb_servo.h"
#include "wesliao_mtb_sonar.h"
#include "Sonar.h"

void setup() {

  Serial.begin(115200);

  mtb_servo_setup();
  mtb_sonar_setup();

  mtb.st.servo.left_wheel.write(15);
  mtb.st.servo.right_wheel.write(165);
  delay(1000);

  mtb.st.servo.left_wheel.write(165);
  mtb.st.servo.right_wheel.write(15);
}

void loop() {

  mtb_sonar_loop();


  delay(50);
}