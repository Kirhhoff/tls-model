#include <stdio.h>
#include "dll.hpp"

struct dll_context
{
  const char *message_;
};

static thread_local dll_context *dll_static_context;

struct dll_context_initializer
{
  dll_context_initializer()
  {
    printf("dll: dll_context_initializer()\n");
    dll_static_context = new dll_context;
  }

  dll_context *get_context() { return dll_static_context; }
};

static thread_local dll_context_initializer dll_static_context_initializer;

thread_local int *dll_global = reinterpret_cast<int *>(0x66666666);
thread_local int *dll_global_preempted_by_dll_relay = reinterpret_cast<int *>(0x99999999);

void dll_reference()
{
  printf("dll_reference: global = %p\n", dll_global);
  printf("dll_reference: dll_global_preempted_by_dll_relay = %p\n", dll_global_preempted_by_dll_relay);

  // comment the following line and "dll_static_context" will be a null pointer
  printf("dll_reference: context intializer = %p\n", &dll_static_context_initializer);
  printf("dll_reference: context = %p\n", dll_static_context);
}