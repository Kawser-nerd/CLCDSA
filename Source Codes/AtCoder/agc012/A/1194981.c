#include<stdio.h>
#include<stdlib.h>

typedef long long ll;
#define N_MAX 100000

int cmp(const void *a, const void *b)
{
	const int *pa, *pb;
	pa=a;
	pb=b;
	if(*pa>*pb) return -1;
	return (*pa<*pb);
}

int main(void)
{
	int N, i;
	static int a[N_MAX*3];
	ll sum;

	while(scanf("%d", &N)==1)
	{
		for(i=0;i<3*N;i++)
		{
			scanf("%d", &a[i]);
		}
		qsort(a, 3*N, sizeof(a[0]), cmp);

		sum=0;
		for(i=0;i<N;i++)
		{
			sum+=a[i*2+1];
		}
		printf("%lld\n", sum);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:26:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%d", &a[i]);
    ^