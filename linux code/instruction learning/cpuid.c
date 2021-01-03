#include <stdio.h>

void showstr(int reg)
{
	int mask = 0xffffff00;
	int shift = 8;
	int i, ch;
	for(i = 0;i < 4;i++)
	{
		ch = reg & ~mask;
		reg >>= shift;
		printf("%c", ch);
	}
	printf("\n");
	return;
}

int main()
{
	int eax, ebx, ecx, edx;
	__asm__ __volatile__("\
		movl $0, %%eax;	\
		cpuid;			\
		movl %%eax, %0;	\
		movl %%ebx, %1;	\
		movl %%ecx, %2;	\
		movl %%edx, %3;	"
		: "=a"(eax), "=b"(ebx), "=c"(ecx), "=d"(edx)
	);
	printf("%d\n%d\n%d\n%d\n", eax, ebx, ecx, edx);
	showstr(ebx);
	showstr(ecx);
	showstr(edx);
	return 0;
}