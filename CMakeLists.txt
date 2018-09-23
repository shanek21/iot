cmake_minimum_required(VERSION 3.10.2) # check for a minimum cmake version
project(iot) # define the project name

include(ExternalProject) # allows use of cmake ExternalProject commands

# Paho MQTT C ######################################################################################

# Define the relative path to paho.mqtt.c, to be referenced later as ${path_paho.mqtt.c}
set(path_paho.mqtt.c external/paho.mqtt.c)
# Define where to look for header files
include_directories(${CMAKE_SOURCE_DIR}/${path_paho.mqtt.c}/src)
# Tell cmake to go into ${path_path.mqtt.c} and execute the CMakeLists.txt there. This
#   command actually builds the paho.mqtt.c library.
ExternalProject_Add(project_paho.mqtt.c
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/${path_paho.mqtt.c}
  PREFIX ${CMAKE_BINARY_DIR}/${path_paho.mqtt.c}
  BINARY_DIR ${CMAKE_BINARY_DIR}/${path_paho.mqtt.c}
  STAMP_DIR ${CMAKE_BINARY_DIR}/${path_paho.mqtt.c}/stamp
  TMP_DIR ${CMAKE_BINARY_DIR}/${path_paho.mqtt.c}/tmp
  # Change the prefix for where to install binaries, libraries, headers, etc.
  CMAKE_ARGS "-DCMAKE_INSTALL_PREFIX=${CMAKE_BINARY_DIR}/${path_paho.mqtt.c}"
    "-DPAHO_WITH_SSL=TRUE" # build SSL-enabled libraries, needed by the paho.mqtt.cpp library
)

# Paho MQTT C++ ####################################################################################

# Define the relative path to paho.mqtt.cpp, to be referenced later as ${path_paho.mqtt.cpp}
set(path_paho.mqtt.cpp external/paho.mqtt.cpp)
# Define where to look for header files
include_directories(${CMAKE_SOURCE_DIR}/${path_paho.mqtt.cpp}/src)
# Tell cmake to go into ${path_path.mqtt.cpp} and execute the CMakeLists.txt there. This
#   command actually builds the paho.mqtt.cpp library.
ExternalProject_Add(project_paho.mqtt.cpp
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/${path_paho.mqtt.cpp}
  PREFIX ${CMAKE_BINARY_DIR}/${path_paho.mqtt.cpp}
  BINARY_DIR ${CMAKE_BINARY_DIR}/${path_paho.mqtt.cpp}
  STAMP_DIR ${CMAKE_BINARY_DIR}/${path_paho.mqtt.cpp}/stamp
  TMP_DIR ${CMAKE_BINARY_DIR}/${path_paho.mqtt.cpp}/tmp
  CMAKE_ARGS "-DPAHO_MQTT_C_PATH=${CMAKE_BINARY_DIR}/external/paho.mqtt.c"
  INSTALL_COMMAND ""
)
# Grab the binary_dir from project_paho.mqtt.cpp, to be referenced later as ${binary_dir}
ExternalProject_Get_Property(project_paho.mqtt.cpp binary_dir)
# Define the paho.mqtt.cpp library,  to be referenced later in target_link_libraries()
add_library(paho.mqtt.cpp SHARED IMPORTED)
# Define the location of the shared library file for paho.mqtt.cpp
set_property(TARGET paho.mqtt.cpp PROPERTY IMPORTED_LOCATION ${binary_dir}/src/libpaho-mqttpp3.so)
# Don't try to build paho.mqtt.cpp until paho.mqtt.c has been built
add_dependencies(project_paho.mqtt.cpp project_paho.mqtt.c)
# Don't try to link the paho.mqtt.cpp library until its project has been built
add_dependencies(paho.mqtt.cpp project_paho.mqtt.cpp)

####################################################################################################

include_directories(${CMAKE_SOURCE_DIR}/include)

file(GLOB SOURCES "src/*.cpp") # define source files, to be referenced later as ${SOURCES}
add_executable(iot ${SOURCES}) # create project executable

# Link paho.mqtt.c shared library into iot executable
target_link_libraries(iot paho.mqtt.cpp)
