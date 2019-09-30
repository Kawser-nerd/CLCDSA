#include<stdio.h>
int main() {
	int N, TM;
	long long ans = 0;
	scanf("%d%d", &N, &TM);
	long long *T = (long long *)malloc(sizeof(long long)*N);
	for (int i = 0; i < N; i++)
	{
		scanf("%lld", &T[i]);
	}

	for (int i = 1; i < N; i++)
	{
		if (T[i]-T[i-1]<TM)
		{
			ans += T[i] - T[i - 1];
		}else
		{
			ans += TM;
		}
	}
	ans += TM;
	printf("%lld\n", ans);

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:30: warning: implicit declaration of function ‘malloc’ [-Wimplicit-function-declaration]
  long long *T = (long long *)malloc(sizeof(long long)*N);
                              ^
./Main.c:6:30: warning: incompatible implicit declaration of built-in function ‘malloc’
./Main.c:6:30: note: include ‘<stdlib.h>’ or provide a declaration of ‘malloc’
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d", &N, &TM);
  ^
./Main.c:9:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld", &T[i]);
   ^