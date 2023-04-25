#include <stdio.h>
#include "dll_relay_internal.hpp"

void dll_relay_component_reference()
{
  printf("dll_relay_component_reference: hidden = %p\n", dll_relay_hidden);
}