#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 100000000
#define TYPE double
#define OP *
int main()
{
	register long i; TYPE* a; register TYPE cc0, cc1, result, *ps, *pe; clock_t begin ,end;
	a = (TYPE*)malloc(sizeof(TYPE) * N);
	for(i=0;i<N;i++)
		a[i] = i;
	
	cc0 = cc1 = result = 0;
	ps = a;
	pe = a + N;
	begin = clock();
	while(ps < pe)
	{
		result = result OP *ps;
		ps++;
	}
	end = clock();
	printf("method-0 --> result:%lf, time:%ld\n", result, end - begin);

	cc0 = cc1 = result = 0;
	ps = a;
	pe = a + N;
	begin = clock();
	while(ps < pe)
	{
		cc0 = cc0 OP *ps;
		ps++;
		cc1 = cc1 OP *ps;
		ps++;
	}
	result = cc0 OP cc1;
	end = clock();
	printf("method-1 --> result:%lf, time:%ld\n", result, end - begin);

	cc0 = cc1 = result = 0;
	ps = a;
	pe = a + N;
	begin = clock();
	while(ps < pe)
	{
		cc0 = *ps++ OP *ps++;
		result = result OP cc0;
	}
	end = clock();
	printf("method-2 --> result:%lf, time:%ld\n", result, end - begin);

	return 0;
}
