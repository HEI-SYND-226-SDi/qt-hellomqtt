cmake_minimum_required(VERSION 3.0)
project(HelloMQTT)

set(CMAKE_AUTOMOC ON)
find_package(Qt5Core)
find_package(Qt5Network)
find_package(Qt5Mqtt)

add_executable(${PROJECT_NAME} main.cpp)
target_link_libraries(${PROJECT_NAME} Qt5::Core Qt5::Network Qt5::Mqtt)