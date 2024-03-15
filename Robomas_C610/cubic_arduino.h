#ifndef CUBIC_ARDUINO_H
#define CUBIC_ARDUINO_H

#define SS_Robomas_C610 10 // SPI通信に用いるピン

class Robomas_C610 {
public:
  static void begin(void);
  void tx_can_message();
  void rx_can_message(targetMessage);
};

#endif