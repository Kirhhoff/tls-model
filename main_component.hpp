extern __attribute__((visibility("hidden"))) thread_local int *executable_hidden;
extern thread_local int *executable_global;

void main_component_reference();