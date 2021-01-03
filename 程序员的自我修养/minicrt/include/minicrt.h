#ifndef _MINI_CRT_H
#define _MINI_CRT_H

#ifdef __cplusplus
extern "C" (
#endif

#ifndef NULL
#define NULL (0)
#endif

void free(void* ptr);
void* malloc(unsigned size);
static int brk(void* end_data_segment);

void mini_crt_entry(void);

int mini_crt_heap_init();

int mini_crt_io_init();

void mini_crt_exit_routine();

#ifdef __cplusplus
)
#endif

#endif
