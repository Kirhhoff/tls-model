cmake_minimum_required(VERSION 3.15)
project(tls-model)

add_library(dll SHARED
  dll.cpp 
)

set_target_properties(dll PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_library(dll_relay SHARED
  dll_relay.cpp 
)

set_target_properties(dll_relay PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_executable(main
  main.cpp
  main_component.cpp
)

set_target_properties(main PROPERTIES POSITION_INDEPENDENT_CODE OFF)

target_link_libraries(main
  dll_relay
  dll
)