#include<stdio.h>
#include<stdlib.h>
#define TYPE long long
int cmp(const void *a, const void *b) { return *(TYPE *)a - *(TYPE *)b; }
int main() {
	long long N,l,r,ans;
	scanf("%lld", &N);
	long long *X = (long long *)malloc(sizeof(long long)*N);
	long long *f = (long long *)malloc(sizeof(long long)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &X[i]);
		f[i] = X[i];
	}

	qsort(f, N, sizeof(long long), cmp);
	l = f[N / 2 - 1];
	r = f[N / 2];
	for (int i = 0; i < N; i++)
	{
		if (X[i]<r)
		{
			ans = r;
		}
		else
		{
			ans = l;
		}
		printf("%lld\n", ans);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &N);
  ^
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &X[i]);
   ^