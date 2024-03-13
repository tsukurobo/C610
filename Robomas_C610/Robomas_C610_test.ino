// Robomas_C610_test.ino (ロボマスモーターのテストファイル)

#include <SPI.h>
#include <mcp_can.h>

#define SS_Robomas_C610 10 // SPI通信に用いるピン


MCP_CAN CAN0(SS_Robomas_C610);

const int CAN_bps = CAN_1000KBPS; // 変更可
const int MCP_OSC = MCP_8MHZ; // 回路上の発振子と合わせる

void mcp2515_init() {
  CAN0.begin(MCP_ANY, CAN_bps, MCP_OSC);
  if(CAN0.begin(MCP_ANY, CAN_bps, MCP_OSC) == CAN_OK) {
    Serial.println("Success : MCP2515 Initialization");}
  else {
    Serial.println("Fail : MCP2515 Initialization");}
  delay(100);
  CAN0.setMode(MCP_NORMAL);
}

void setup() {
  Serial.begin(9600);
  mcp2515_init();
}


void tx_can_message() {
  uint32_t tx_message = 0x200;
  uint8_t tx_data[8] = {0x07, 0xD0, 0x00, 0x00, 0x0, 0x0, 0x0, 0x0};

  Serial.print("Sending CAN message: ID=");
  Serial.print(tx_message, HEX);
  Serial.print("  ");
  Serial.print("Sending CAN data= ");
  CAN0.sendMsgBuf(tx_message, 0, 8, tx_data);
  for (int i = 0; i < 8; i++) {
    Serial.print(tx_data[i], HEX);
    Serial.print(" ");
  }
  Serial.println();
  delay(100);
  
}

void rx_can_message() {
  unsigned char len = 0;
  unsigned char data[8];
  unsigned long int rx_message;

  if (CAN_MSGAVAIL == CAN0.checkReceive()) {
    
    CAN0.readMsgBuf(&rx_message, &len, data);
    
    // ID=0x201のデータのみを表示
    if (rx_message == 0x201) {
      Serial.print("Receiving CAN message: ID= ");
      Serial.print(rx_message, HEX);
      Serial.print("  ");
      Serial.print("Receiving CAN data= ");
      for (int i = 0; i < len; i++) {
        Serial.print(data[i], HEX);
        Serial.print(" ");
      }
      Serial.println();
      delay(100);
    }
  }
}

void loop() {
  tx_can_message();
  rx_can_message();
}