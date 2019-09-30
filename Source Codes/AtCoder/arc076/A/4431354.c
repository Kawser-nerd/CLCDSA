#include<stdio.h>
#include<math.h>
int main() {
	long long N, M;
	long long ans = 0;
	long long tmpn = 1, tmpm = 1;
	scanf("%lld%lld", &N, &M);
	if (abs(N - M) > 1)
	{
		printf("%lld\n", ans);
	}
	else
	{
		for (long long i = 1; i <= N; i++)
		{
			tmpn = (tmpn * i) % 1000000007;

		}
		for (long long i = 1; i <= M; i++)
		{
			tmpm = (tmpm * i) % 1000000007;

		}
		ans = tmpn * tmpm;
		if (N == M)
		{
			ans *= 2;
		}
		ans = ans % 1000000007;
		printf("%lld\n", ans);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:6: warning: implicit declaration of function ‘abs’ [-Wimplicit-function-declaration]
  if (abs(N - M) > 1)
      ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^