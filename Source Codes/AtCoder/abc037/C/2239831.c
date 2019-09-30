#include <stdio.h>
#include <stdlib.h>
#define min(a,b) (((a)<(b))?(a):(b))
int main() {
	long int n, k, a, i, kk;
	long long int ans = 0;
	scanf("%ld%ld", &n, &k);
	kk = min(k, n - k + 1);
	for (i = 0; i < n; i++)
	{
		scanf("%ld", &a);
		ans += a*min(min(i + 1, n - i), kk);
	}
	printf("%lld", ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%ld%ld", &n, &k);
  ^
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &a);
   ^