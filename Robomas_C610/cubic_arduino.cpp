#include "cubic_arduino.h"
#include "CanReceiver.h"
#include <SPI.h>
#include <mcp_can.h>

MCP_CAN CAN0(SS_Robomas_C610);  // SS_Robomas_C610ピンを使うCANをCAN0としてインスタンスを作成
// Robomas_C610 robomas; // Robomas_C610クラスのインスタンスを作成(.cppがこのインスタンスを所有←こっちの方が良いの？)

const int CAN_bps = CAN_1000KBPS;
const int MCP_OSC = MCP_8MHZ; // 回路の設計変更の時のみ変更可

void mcp2515_init() {
  CAN0.begin(MCP_ANY, CAN_bps, MCP_OSC);
  if (CAN0.begin(MCP_ANY, CAN_bps, MCP_OSC) == CAN_OK) {
    Serial.println("Success : MCP2515 Initialization");
  } else {
    Serial.println("Fail : MCP2515 Initialization");
  }
  delay(100);
  CAN0.setMode(MCP_NORMAL);
}

void Robomas_C610::begin(void) {
  mcp2515_init();
}

void Robomas_C610::tx_can_message() {
  uint32_t tx_message = 0x200;
  uint8_t tx_data[8] = {0x03, 0xE8, 0x00, 0x00, 0x0, 0x0, 0x0, 0x0};

  Serial.print("Sending CAN message: ID=");
  Serial.println(tx_message, HEX);
  canModule.sendMsgBuf(tx_message, 0, 8, tx_data);

  for (int i = 0; i < 8; i++) {
    Serial.print(tx_data[i], HEX);
    Serial.print(" ");
  }

  Serial.println();
  delay(10);
}

void Robomas_C610::rx_can_message(targetMessage) {
  canReceiver.receiveAndPrintData(getTargetMessage());
}