#include "minicrt.h"

#ifdef WIN32
#include <windows.h>
#endif

extern int main(int argc, char* argv[]);
void exit(int);

static void crt_fatal_error(const char* msg)
{
	//printf("fatal error: %s", msg);
	exit(1);
}

void mini_crt_entry(void)
{
	int ret;
#ifdef WIN32
	int flag = 0;
	int argc = 0;
	char* argv[16];				// 最多16个参数
	char* cl = GetCommandLineA();

	// 解析命令行
	argv[0] = cl;
	argc++;
	while(*cl)
	{
		if(*cl == '\"')
			if(flag == 0)	flag = 1;
			else flag = 0;
		else if(*cl == ' ' && flag == 0)
		{
			if(*(cl+1))
			{
				argv[argc] = cl + 1;
				argc++;
			}
			*cl = '\0';		// 截断
		}
		cl++;
	}
#else
	int argc;
	char** argv;

	char* rbp_reg = 0;
	asm("movq %%rbp, %0 \n" : "=r"(rbp_reg));

	argc = *(int*)(rbp_reg + 8);
	argv = (char**)(rbp_reg + 16);

#endif

	if(!mini_crt_heap_init())
		crt_fatal_error("Heap initialize failed");
	if(!mini_crt_io_init())
		crt_fatal_error("IO initialize failed");

	ret = main(argc, argv);
	exit(ret);
}

void exit(int exitCode)
{
	//mini_crt_call_exit_routine();
#ifdef WIN32
	ExitProcess(exitCode);
#else
	asm(
		"movq %0, %%rbx \n\t"
		"movq $1, %%rax \n\t"
		"int $0x80	\n\t"
		"hlt		\n\t"::"m"(exitCode));
#endif
}

