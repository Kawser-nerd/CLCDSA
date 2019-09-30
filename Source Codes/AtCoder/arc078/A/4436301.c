#include<stdio.h>
#include <stdlib.h>
int main() {
	int N;
	scanf("%d", &N);
	long long *A = (long long *)malloc(sizeof(long long)*N);
	long long cltsum = 0, total = 0;
	long long tmp = 0, min = 100000000000;
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &A[i]);
		total += A[i];
	}
	for (int i = 0; i < N - 1; i++)
	{
		cltsum += A[i];
		tmp = llabs(cltsum - (total - cltsum));
		if (tmp < min)
		{
			min = tmp;
		}
	}
	printf("%lld\n", min);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &A[i]);
   ^