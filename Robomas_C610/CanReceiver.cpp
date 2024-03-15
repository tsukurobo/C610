#include "CanReceiver.h"
//#include <Arduino.h>

CanReceiver::CanReceiver(MCP_CAN &canModule) : canModule(canModule) {}

void CanReceiver::receiveAndPrintData(unsigned long targetMessage) {
  unsigned char len = 0;
  unsigned char rx_data[8];
  unsigned long rx_message;

  if (CAN_MSGAVAIL == canModule.checkReceive()) {
    canModule.readMsgBuf(&len, rx_data, &rx_message);

    if (rx_message == targetMessage) {
      Serial.print("Receiving CAN message: ID=");
      Serial.println(rx_message, HEX);
      for (int i = 0; i < len; i++) {
        Serial.print(rx_data[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      delay(10);
    }
  }
}