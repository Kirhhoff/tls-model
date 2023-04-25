cmake_minimum_required(VERSION 3.15)
project(tls-model)

option(enable_optimization "" ON)
option(enable_PIE "" ON)
option(enable_dll_symbol_preemption "" ON)

if (${enable_optimization})
  add_compile_options(-O3)
endif()

add_library(dll SHARED
  dll.cpp 
)

set_target_properties(dll PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_custom_command(
  TARGET dll
  POST_BUILD
  COMMAND objdump -s -S libdll.so > libdll.so.asm
  COMMAND nm -g -C libdll.so > libdll.so.sym
)

add_library(dll_relay SHARED
  dll_relay.cpp 
  dll_relay_component.cpp 
)

set_target_properties(dll_relay PROPERTIES POSITION_INDEPENDENT_CODE ON)

add_custom_command(
  TARGET dll_relay
  POST_BUILD
  COMMAND objdump -s -S libdll_relay.so > libdll_relay.so.asm
  COMMAND nm -g -C libdll_relay.so > libdll_relay.so.sym
)

add_executable(main
  main.cpp
  main_component.cpp
)

if (${enable_dll_symbol_preemption})
  # with such dependency order, @dll_global_preempted_by_dll_relay will be 0x88888888
  target_link_libraries(main
    dll_relay
    dll
  )
else()
  # with such dependency order, @dll_global_preempted_by_dll_relay will be 0x99999999
  target_link_libraries(main
    dll
    dll_relay
  )
endif()

set_target_properties(main PROPERTIES POSITION_INDEPENDENT_CODE ${enable_PIE})

add_custom_command(
  TARGET main
  POST_BUILD
  COMMAND objdump -s -S main > main.asm
  COMMAND nm -g -C main > main.sym
)

file(
  GLOB asm_and_sym_files
  RELATIVE ${PROJECT_BINARY_DIR}
  ${PROJECT_BINARY_DIR}/*.asm
  ${PROJECT_BINARY_DIR}/*.sym
)

set_directory_properties(
  PROPERTY ADDITIONAL_MAKE_CLEAN_FILES
  "${asm_and_sym_files}"
)