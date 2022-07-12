#include <XboxSeriesXControllerESP32_asukiaaa.hpp>
#include "Steering.h"
// Required to replace with your xbox address
// XboxSeriesXControllerESP32_asukiaaa::Core xboxController("44:16:22:5e:b2:d4");
XboxSeriesXControllerESP32_asukiaaa::Core xboxController; // any xbox controller

void setup() {
  Serial.begin(115200);
  Serial.println("Starting NimBLE Client");
  xboxController.begin();
}

void loop() {
  xboxController.onLoop();
  if (xboxController.isConnected()) {
    Serial.print(xboxController.xboxNotif.toString());
    unsigned long receivedAt = xboxController.getReceiveNotificationAt();
    uint16_t joystickMax = XboxControllerNotificationParser::maxJoy;
    Serial.print("joyLHori rate: ");
    Serial.println((float) xboxController.xboxNotif.joyLHori / joystickMax);
    Serial.print("joyLVert rate: ");
    Serial.println((float) xboxController.xboxNotif.joyLVert / joystickMax);
    Serial.println("received at " + String(receivedAt));
  } else {
    Serial.print("not connected");
  }
  Serial.println(" at " + String(millis()));
  delay(500);
}