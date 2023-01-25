cmake_minimum_required(VERSION 3.24)
project(tcpCreateForBank C)

set(CMAKE_C_STANDARD 11)

add_executable(tcpCreateForBank tcp_client.c tcp_server.c server.h)
