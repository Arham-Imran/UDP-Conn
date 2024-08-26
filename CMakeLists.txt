cmake_minimum_required(VERSION 3.5.0)
project(UDP_Conn VERSION 0.1.0 LANGUAGES C)

add_executable(UDP_Server UDP_Server.c)
add_executable(UDP_Client UDP_Client.c)
