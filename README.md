# iot

## Goal

This project aims to simplify the process of connecting remote sensors, a central database, and a visualization platform. It arises from the problem that it is far too difficult to do simple data collection and analysis projects such as collecting temperature information from your backyard.

## Setup

### Install

#### Install CMake

```bash
$ sudo apt install cmake
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

## References

### CMake

* [Introduction to CMake by Example](http://derekmolloy.ie/hello-world-introductions-to-cmake/#Example_3_Building_a_Shared_Library_so)
* [CMake by Example](https://mirkokiefer.com/cmake-by-example-f95eb47d45b1)

### MQTT

* [MQTT Essentials](https://www.hivemq.com/mqtt-essentials/)

### Paho MQTT C

* [Documentation](http://www.eclipse.org/paho/files/mqttdoc/MQTTClient/html/index.html)
* [Publishing Example](https://www.eclipse.org/paho/clients/c/)

### Paho MQTT C++

* [Documentation](http://www.eclipse.org/paho/files/cppdoc/index.html)
