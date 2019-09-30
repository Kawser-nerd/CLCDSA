#include<stdio.h>
int main() {
	long long N, M, ans = 0;
	scanf("%lld%lld", &N, &M);

	if (M >= N * 2)//N:M <= 1:2
	{
		ans += N;
		M -= 2 * N;
		ans += M / 4;
	}
	else if (M < N * 2)//N:M > 1:2
	{
		ans += M/2;
	}
	printf("%lld\n", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld", &N, &M);
  ^