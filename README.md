# iot

![System Diagram](media/final/system_diagram.png)

## Goal

This project aims to simplify the process of connecting remote sensors, a central database, and a visualization platform. It arises from the problem that it is far too difficult to do simple data collection and analysis projects such as collecting temperature information from your backyard.

## Setup

### Install

#### Install CMake

```bash
$ sudo apt install cmake
```

#### Install Mosquitto

```bash
$ sudo apt install mosquitto mosquitto-client
```

#### Populate all of the Git submodules

```bash
$ git submodule update --init
```

### Build

```bash
$ mkdir build
$ cd build
$ cmake ..
$ make
```

### Run

```bash
$ ./build/iot
```

## Dependencies

* [Paho MQTT C](https://github.com/eclipse/paho.mqtt.c): `external/paho.mqtt.c`
* [Paho MQTT C++](https://github.com/eclipse/paho.mqtt.cpp): `external/paho.mqtt.cpp`

## References

### CMake

* [Introduction to CMake by Example](http://derekmolloy.ie/hello-world-introductions-to-cmake/#Example_3_Building_a_Shared_Library_so)
* [CMake by Example](https://mirkokiefer.com/cmake-by-example-f95eb47d45b1)

### Mosquitto

* [Installing and Testing Mosquitto MQTT on the Raspberry Pi](http://www.switchdoc.com/2016/02/tutorial-installing-and-testing-mosquitto-mqtt-on-raspberry-pi/)
* [Configuring MQTT on the Raspberry Pi](http://www.switchdoc.com/2016/02/tutorial-installing-and-testing-mosquitto-mqtt-on-raspberry-pi/)

### MQTT

* [MQTT Essentials](https://www.hivemq.com/mqtt-essentials/)

### Paho MQTT C

* [Documentation](http://www.eclipse.org/paho/files/mqttdoc/MQTTClient/html/index.html)
* [Publishing Example](https://www.eclipse.org/paho/clients/c/)

### Paho MQTT C++

* [Documentation](http://www.eclipse.org/paho/files/cppdoc/index.html)
