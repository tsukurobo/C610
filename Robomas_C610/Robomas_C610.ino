#include <SPI.h>
#include <mcp_can.h>
#include "CanReceiver.h"
#include "cubic_arduino.h"

const int CAN_bps = CAN_1000KBPS;
const int MCP_OSC = MCP_8MHZ;

//Robomas_C610 robomas;  // Robomas_C610クラスのインスタンスを作成(.inoがこのインスタンスを所有←こっちの方が良いの？インクルード元.cppでインスタンスを作成する方針とする)

void setup() {
  Serial.begin(9600);
  robomas.begin();  // Robomas_C610クラスの初期化処理
}

void loop() {
  robomas.tx_can_message();
  motorId = 0x201; //motorIdはRosから受け取りたい。
  robomas.rx_can_message(motorId);
}