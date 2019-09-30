#include<stdio.h>
#include<stdlib.h>
#include<string.h>


typedef int (*cmp_t)(const void *, const void *);


#define N_MAX 100000


int cmp(const int *a, const int *b)
{
	return *a-*b;
}


int main(void)
{
	int N, i;
	static int A[N_MAX];
	static double B[N_MAX];
	int count;

	while(scanf("%d", &N)==1)
	{
		for(i=0;i<N;i++)
		{
			scanf("%d", &A[i]);
		}
		qsort(A, N, sizeof(A[0]), (cmp_t)cmp);

		B[0]=A[0];
		for(i=1;i<N;i++)
		{
			B[i]=B[i-1]+A[i];
		}

		count=1;
		for(i=1;i<N;i++)
		{
			if(A[i]<=2*B[i-1])
			{
				count++;
			}
			else
			{
				count=1;
			}
		}
/*
for(i=0;i<N;i++) printf(" %d[%d]", A[i], B[i]);
printf("\n");
*/
		printf("%d\n", count);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &A[i]);
    ^