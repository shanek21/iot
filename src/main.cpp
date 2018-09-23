#include "mqtt_logger.h"


int main() {
  MqttLogger mqtt_subscriber("tcp://localhost:1883", "subscriber", "temperature", 0);
  return 0;
}
