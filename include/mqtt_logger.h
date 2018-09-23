/*
 * MqttLogger serves as a way to persist data from an MQTT connection. An MQTT subscriber connects
 * to the MQTT broker and stores all incoming messages in a database.
 */


#ifndef MQTT_LOGGER_H
#define MQTT_LOGGER_H


#include "mqtt/client.h"


class MqttLogger {
public:
  /**
   * Constructor for MqttLogger. Attempts to connect to an MQTT broker at server_address.
   * * @param server_address - The address of the MQTT broker that will attempt to be connected to.
   * @param client_id - The ID of the mqtt::client object to create.
   * @param topic_filter - The topic filter used to subscribe to topics from the MQTT broker.
   * @param qos - The quality of service for the MQTT client.
  */
  MqttLogger(const std::string server_address, const std::string client_id,
      const std::string topic_filter, const int qos);

  /**
   * Destructor for MqttLogger. Attempts to disconnect from the MQTT broker.
   */
  ~MqttLogger();

  /**
   * Serves as a wrapper around mqtt::client.connect() with some error handling.
   */
  void connect();

  /**
   *
   */
  void subscribe();

  /**
   * Serves as a wrapper around mqtt::client.disconnect() with some error handling.
   */
  void disconnect();

private:
  const std::string server_address; // the address of the MQTT broker
  const std::string client_id; // the ID of the MQTT client
  mqtt::client mqtt_client; // the Paho MQTT client that will try to interface with the MQTT broker
  const std::string topic_filter; // the topic filter used to subscribe to topics
  const int qos; // the quality of service for the MQTT client
};


#endif // MQTT_LOGGER_H
