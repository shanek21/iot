#include <iostream>
#include <stdexcept>

#include "mqtt_logger.h"


MqttLogger::MqttLogger(const std::string server_address, const std::string client_id,
    const std::string topic_filter, const int qos)
    : server_address(server_address), client_id(client_id), mqtt_client(server_address, client_id),
    topic_filter(topic_filter), qos(qos) {
  this->connect();
  this->subscribe();
}


MqttLogger::~MqttLogger() {
  this->disconnect();
}


void MqttLogger::connect() {
  std::cout << "Connecting to the MQTT server at " << server_address << "..." << std::endl;
  try {
    mqtt_client.connect();
  } catch (const mqtt::exception& exception) {
    std::cerr << "  Error: Unable to connect to the MQTT server at " << server_address << "." <<
        std::endl;
    throw exception;
  }

  std::cout << "  Successfully connected to the MQTT server at " << server_address << "." <<
      std::endl;
}


void MqttLogger::subscribe() {
  std::cout << "Subscribing to topics with topic filter \"" << topic_filter << "\" and QoS " << qos
    << std::endl;
  try {
    mqtt_client.subscribe(topic_filter, qos);
  } catch (const mqtt::exception& exception) {
    std::cerr << "  Unable to subscribe to topics with topic filter \"" << topic_filter <<
      "\" and QoS " << qos << "." << std::endl;
    throw exception;
  }

  std::cout << "  Successfully subscribed to topics with topic filter \"" << topic_filter <<
    "\" and QoS " << qos << "." << std::endl;
}


void MqttLogger::disconnect() {
  std::cout << "Disconnecting from the MQTT server at " << server_address << "..." << std::endl;
  try {
    mqtt_client.disconnect();
  } catch (const mqtt::exception& exception) {
    std::cerr << "  Error: Unable to disconnect from the MQTT server at " << server_address << "." <<
        std::endl;
    throw exception;
  }

  std::cout << "  Successfully disconnected from the MQTT server at " << server_address << "." <<
      std::endl;
}
