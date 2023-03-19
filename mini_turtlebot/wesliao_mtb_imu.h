#include "FastIMU.h"

void mtb_imu_setup() {
  mtb.st.imu.imu.init(mtb.st.imu.calibration, mtb.cfg.imu.address);
  mtb.st.imu.imu.calibrateAccelGyro(&mtb.st.imu.calibration);
}


void mtb_imu_loop() {
  mtb.st.imu.imu.update();

  mtb.st.imu.imu.getAccel(&mtb.st.imu.accel);
  Serial.print("\t");
  Serial.print(mtb.st.imu.accel.accelX);
  Serial.print("\t");
  Serial.print(mtb.st.imu.accel.accelY);
  Serial.print("\t");
  Serial.print(mtb.st.imu.accel.accelZ);
  Serial.print("\t");
  mtb.st.imu.imu.getGyro(&mtb.st.imu.gyro);
  Serial.print(mtb.st.imu.gyro.gyroX);
  Serial.print("\t");
  Serial.print(mtb.st.imu.gyro.gyroY);
  Serial.print("\t");
  Serial.print(mtb.st.imu.gyro.gyroZ);
  Serial.print("\t");
  Serial.print(mtb.st.imu.imu.getTemp());
}