cmake_minimum_required(VERSION 3.10.2) # check for a minimum cmake version
project(iot) # define the project name

include(ExternalProject) # allows use of cmake ExternalProject commands

# Define the relative path to paho.mqtt.c, to be referenced later as ${path_paho.mqtt.c}
set(path_paho.mqtt.c external/paho.mqtt.c)
# Tell cmake to go into ${path_path.mqtt.c} and execute the CMakeLists.txt there. This
#   command actually builds the paho.mqtt.c library.
ExternalProject_Add(project_paho.mqtt.c
  SOURCE_DIR ${CMAKE_SOURCE_DIR}/${path_paho.mqtt.c}
  PREFIX ${CMAKE_BINARY_DIR}/${path_paho.mqtt.c}
  BINARY_DIR ${CMAKE_BINARY_DIR}/${path_paho.mqtt.c}
  STAMP_DIR ${CMAKE_BINARY_DIR}/${path_paho.mqtt.c}/stamp
  TMP_DIR ${CMAKE_BINARY_DIR}/${path_paho.mqtt.c}/tmp
  INSTALL_COMMAND ""
)
# Grab the binary_dir from project_paho.mqtt.c, to be referenced later as ${binary_dir}
ExternalProject_Get_Property(project_paho.mqtt.c binary_dir)

# Define the paho.mqtt.c library to be referenced later in target_link_libraries()
add_library(paho.mqtt.c SHARED IMPORTED)
# Define the location of the shared library file for paho.mqtt.c
set_property(TARGET paho.mqtt.c PROPERTY IMPORTED_LOCATION ${binary_dir}/src/libpaho-mqtt3c.so)
# Don't try to link the library until it's project has been built
add_dependencies(paho.mqtt.c project_paho.mqtt.c)

file(GLOB SOURCES "src/*.c") # define source files, to be referenced later as ${SOURCES}
add_executable(iot ${SOURCES}) # create project executable

# Define where to look for header files
include_directories(${CMAKE_SOURCE_DIR}/${path_paho.mqtt.c}/src)

target_link_libraries(iot paho.mqtt.c) # link paho.mqtt.c shared library into iot executable
