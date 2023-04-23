#include <stdio.h>
#include "dll_relay.hpp"
#include "dll.hpp"
#include "main_component.hpp"

void main_reference()
{
  printf("main_reference: global = %p\n", executable_global);
}

int main()
{
  main_reference();
  main_component_reference();
  dll_relay_reference();
  dll_reference();
}