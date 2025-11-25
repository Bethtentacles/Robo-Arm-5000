#include <Arduino.h>
#include <Wire.h>
#include "PCA9685.h"
#include "Drive.h"
#include "Servo_c.h"

// PCA9685 I2C servo driver
PCA9685 pca(B000000, Wire, 400000);

// Drive instance: (pot pin, low offset, high offset, pot angle, pca instance, channel, min limit, max limit)
Drive base_rotation      (A0, 0, 1023, 270, &pca, 0, 0, 270);
Drive elbow_drive        (A1, 0, 1023, 270, &pca, 1, 0, 270);
Drive wrist_drive        (A2, 0, 1023, 270, &pca, 2, 0, 270);
Drive End_effector_drive (A3, 0, 1023, 270, &pca, 3, 0, 270);

void setup() {
  Serial.begin(115200);
  delay(10);
  
  Serial.println("running pca9685 setup");
  Wire.begin();
  pca.resetDevices();
  pca.init(
    PCA9685_OutputDriverMode_TotemPole,
    PCA9685_OutputEnabledMode_Normal,
    PCA9685_OutputDisabledMode_Low,
    PCA9685_ChannelUpdateMode_AfterStop,
    PCA9685_PhaseBalancer_None
  );
  pca.setPWMFrequency(50);
  Serial.println("PCA9685 ready");
  
  base_rotation.begin();
  elbow_drive.begin();
  wrist_drive.begin();
  // End_effector_drive.begin();

  delay(2000);
}

void loop() {
  base_rotation.update();
  elbow_drive.update();
  wrist_drive.update();
  // End_effector_drive.update();
  
  Serial.print(" Base rotation angle: ");
  Serial.println(base_rotation.servo.getAngle());
  delay(50);
}
