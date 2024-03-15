#ifndef CAN_RECEIVER_H
#define CAN_RECEIVER_H

#include <mcp_can.h>

class CanReceiver {
public:
  CanReceiver(MCP_CAN &canModule);
  void receiveAndPrintData(unsigned long targetMessage);

private:
  MCP_CAN &canModule;
};

#endif