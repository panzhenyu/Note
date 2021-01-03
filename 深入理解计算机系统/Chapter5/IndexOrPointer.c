#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define N 10000000
#define TYPE long

int main()
{
	TYPE *a; register TYPE *ps, *pe, result; register int i; clock_t begin, end;
	a = (TYPE*)malloc(sizeof(TYPE) * N);
	for(i=0;i<N;i++)
		a[i] = i;

	result = 0;
	begin = clock();
	for(i=0;i<N;i++)
		result = result + a[i];
	end = clock();
	printf("method-0 --> result=%ld, time=%d\n", result, end - begin);

	result = 0;
	begin = clock();
	ps = a;
	pe = a + N;
	while(ps < pe)
	{
		result = result + *ps;
		ps++;
	}
	end = clock();
	printf("method-1 --> result=%ld, time=%d\n", result, end - begin);

	return 0;
}
