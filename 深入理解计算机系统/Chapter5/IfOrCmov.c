#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define N 1000000

int main()
{
	int i, *a, *b, *c, *d, m, n, t; clock_t start, end; FILE *fp = fopen("output.txt", "w");
	a = (int*)malloc(sizeof(int) * N);
	b = (int*)malloc(sizeof(int) * N);
	c = (int*)malloc(sizeof(int) * N);
	d = (int*)malloc(sizeof(int) * N);
	for(i=0;i<N;i++)
	{
		a[i] = rand()%10000;
		b[i] = rand()%10000;
		c[i] = a[i];
		d[i] = b[i];
	}
	
	start = clock();
	for(i=0;i<N;i++)
	{
		if(a[i] < b[i])
		{
			m = a[i];
			a[i] = b[i];
			b[i] = m;
		}
	}
	end = clock();
	printf("use if takes time:%d\n", end - start);

	start = clock();
	for(i=0;i<N;i++)
	{
		t = c[i] < d[i];
		m = t ? c[i] : d[i];
		n = t ? d[i] : c[i];
		c[i] = n;
		d[i] = m;
	}
	end = clock();
	printf("use cmov takes time:%d\n", end - start);

	for(i=0;i<N;i++)
		fprintf(fp, "%d,%d,%d,%d\n", a[i], b[i], c[i], d[i]);
	return 0;
}
