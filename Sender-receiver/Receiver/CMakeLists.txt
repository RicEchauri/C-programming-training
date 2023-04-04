cmake_minimum_required(VERSION 3.0)
project(receiver) 
#incluir los headers 
include_directories(include)
add_executable(
    receiver-executable #binario
    src/main.c
    src/receiver.c
)
