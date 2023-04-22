#include <stdio.h>
#include "dll_relay.hpp"
#include "main_component.hpp"

static thread_local int *executable_static = reinterpret_cast<int *>(0x11111111);
__attribute__((visibility("hidden"))) thread_local int *executable_hidden = reinterpret_cast<int *>(0x22222222);
thread_local int *executable_global = reinterpret_cast<int *>(0x33333333);
thread_local int *dll_relay_global_preempted = reinterpret_cast<int *>(0x88888888);

void main_component_reference()
{
  printf("main_component_reference: static = %p\n", executable_static);
  printf("main_component_reference: hidden = %p\n", executable_hidden);
  printf("main_component_reference: global = %p\n", executable_global);
  printf("main_component_reference: dll_relay global = %p\n", dll_relay_global);
  printf("main_component_reference: dll_relay_global_preempted = %p\n", dll_relay_global_preempted);
}