#include <stdio.h>
#include "dll.hpp"

thread_local int *dll_global = reinterpret_cast<int *>(0x77777777);

void dll_reference()
{
  printf("dll_reference: global = %p\n", dll_global);
}