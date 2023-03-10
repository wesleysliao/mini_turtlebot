
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

  switch(mtb.st.sonar.forward.update()) {
    case Sonar::IDLE:
      mtb.st.sonar.forward.trigger();
      break;
    
    case Sonar::READY:
      Serial.println(mtb.st.sonar.forward.read_cm());
      break;
  }
  delay(10);
}