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

# with such dependency order, @dll_global_preempted_by_dll_relay will be 0x99999999
target_link_libraries(main
  dll_relay
  dll
)

# with such dependency order, @dll_global_preempted_by_dll_relay will be 0x88888888
# target_link_libraries(main
#   dll
#   dll_relay
# )