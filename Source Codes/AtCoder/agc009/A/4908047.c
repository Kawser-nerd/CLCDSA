#include<stdio.h>
int main() {
	int N;
	long long tmp = 0, ans = 0;
	scanf("%d", &N);
	long long *A = (long long *)malloc(sizeof(long long)*N);
	long long *B = (long long *)malloc(sizeof(long long)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld%lld", &A[i], &B[i]);
	}
	//for (int i = 0; i < N; i++)
	//{
	//	printf("%lld %lld\n", A[i], B[i]);

	//}
	for (int i = N - 1; i >= 0; i--)
	{
		tmp += (B[i] - (A[i] + tmp) % B[i]) % B[i];
	}
	ans = tmp;
	printf("%lld\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:30: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
  long long *A = (long long *)malloc(sizeof(long long)*N);
                              ^
./Main.c:6:30: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:6:30: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &N);
  ^
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld%lld", &A[i], &B[i]);
   ^