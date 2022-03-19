cmake_minimum_required(VERSION 3.21)
project(SimpleSockets)

set(CMAKE_CXX_STANDARD 14)

add_executable(simple-socket-server Server/server.cpp)

add_executable(simple-socket-client Client/client.cpp)
