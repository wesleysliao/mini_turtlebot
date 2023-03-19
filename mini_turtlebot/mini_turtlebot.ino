
#include "wesliao_mtb_struct.h"
#include "wesliao_mtb_servo.h"
#include "wesliao_mtb_sonar.h"
#include "wesliao_mtb_imu.h"
#include "Sonar.h"

void setup() {

  Serial.begin(115200);

  mtb_servo_setup();
  mtb_sonar_setup();
  mtb_imu_setup();

  mtb.st.servo.left_wheel.write(15);
  mtb.st.servo.right_wheel.write(165);
  delay(1000);

  mtb.st.servo.left_wheel.write(165);
  mtb.st.servo.right_wheel.write(15);
}

void loop() {

  mtb_sonar_loop();
  mtb_imu_loop();

  Serial.print("\n");

  delay(50);
}