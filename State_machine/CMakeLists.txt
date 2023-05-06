cmake_minimum_required(VERSION 3.0)
project(Satate_state) 
#incluir los headers 
include_directories(include)
add_executable(
    #main    
    state_machine #binario
    src/main.c
    src/coin_state_machine.c
)
