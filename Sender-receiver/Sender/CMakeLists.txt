cmake_minimum_required(VERSION 3.0)
project(sender) 
#incluir los headers 
include_directories(include)
add_executable(
    sender-executable #binario
    src/main.c
    src/sender.c
)
