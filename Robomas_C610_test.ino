#include <SPI.h>
#include <mcp_can.h>

const int spiCS = 10; // Chip select pin
MCP_CAN CAN0(spiCS);  // Set CS pin

const int CAN_bps = CAN_1000KBPS; 
const int MCP_OSC = MCP_8MHZ;

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
  mcp2515_init(); /*起動時の操作*/
}


void tx_can_message() {
  uint32_t tx_message = 0x200;
  uint8_t tx_data[8] = {0x03, 0xE8, 0x00, 0x00, 0x0, 0x0, 0x0, 0x0};

  while (true) {
    Serial.print("Sending CAN message: ID=");
    Serial.println(tx_message, HEX);
    CAN0.sendMsgBuf(tx_message, 0, 8, tx_data);
    for (int i = 0; i < 8; i++) {
      Serial.print(tx_data[i], HEX);
      Serial.print(" ");
    }
    Serial.println();
    delay(100);
  }
}

void loop() {
  tx_can_message();
}
