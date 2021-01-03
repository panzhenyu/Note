#include <stdio.h>
// #pragma section(".CRT$XCB", long, read)									// msvc version
// #pragma section(".CRT$XCZ", long, read)									// msvc version

void /*__attribute__((constructor))*/ my_init()
{
	printf("Hello ");
}

void /*__attribute__((destructor))*/ my_dest()
{
	printf("World!\n");
}

typedef void (*ctor_t)();

ctor_t __attribute__((section(".ctor"))) my_init_p = &my_init;
// ctor_t __declspec(allocate(".CRT$XCB")) my_init_p = &my_init;			// msvc version

typedef void (*dtor_t)();

dtor_t __attribute__((section(".dtor"))) my_dest_p = &my_dest;
// dtor_t __declspec(allocate(".CRT$XCZ")) my_dest_p = &my_dest;			// msvc version

int main()
{
	return 0;
}
