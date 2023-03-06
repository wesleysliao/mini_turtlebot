#include <ESP32Servo.h>


void mtb_servo_setup() {

	ESP32PWM::allocateTimer(0);
	ESP32PWM::allocateTimer(1);
	ESP32PWM::allocateTimer(2);
	ESP32PWM::allocateTimer(3);

  mtb.st.servo.left_wheel.attach(mtb.cfg.servo.left_wheel.pin, 
                                 mtb.cfg.servo.left_wheel.pulse_min_us,
                                 mtb.cfg.servo.left_wheel.pulse_max_us);

  mtb.st.servo.right_wheel.attach(mtb.cfg.servo.right_wheel.pin, 
                                  mtb.cfg.servo.right_wheel.pulse_min_us,
                                  mtb.cfg.servo.right_wheel.pulse_max_us);

}