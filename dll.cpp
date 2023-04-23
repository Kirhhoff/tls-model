#include <stdio.h>
#include "dll.hpp"

thread_local int *dll_global = reinterpret_cast<int *>(0x66666666);
thread_local int *dll_global_preempted_by_dll_relay = reinterpret_cast<int *>(0x99999999);

void dll_reference()
{
  printf("dll_reference: global = %p\n", dll_global);
  printf("dll_reference: dll_global_preempted_by_dll_relay = %p\n", dll_global_preempted_by_dll_relay);
}