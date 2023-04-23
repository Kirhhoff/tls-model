#include <stdio.h>
#include "dll.hpp"
#include "dll_relay.hpp"
#include "dll_relay_internal.hpp"

static thread_local int *dll_relay_static = reinterpret_cast<int *>(0x44444444);
__attribute__((visibility("hidden"))) thread_local int *dll_relay_hidden = reinterpret_cast<int *>(0x55555555);
thread_local int *dll_relay_global = reinterpret_cast<int *>(0x66666666);
thread_local int *dll_relay_global_preempted_by_executable = reinterpret_cast<int *>(0x99999999);
thread_local int *dll_global_preempted_by_dll_relay = reinterpret_cast<int *>(0x99999999);

void dll_relay_reference()
{
  printf("dll_relay_reference: static = %p\n", dll_relay_static);
  printf("dll_relay_reference: hidden = %p\n", dll_relay_hidden);
  printf("dll_relay_reference: global = %p\n", dll_relay_global);
  printf("dll_relay_reference: dll global = %p\n", dll_global);
  printf("dll_relay_reference: dll_relay_global_preempted_by_executable = %p\n", dll_relay_global_preempted_by_executable);
  printf("dll_relay_reference: dll_global_preempted_by_dll_relay = %p\n", dll_global_preempted_by_dll_relay);
}