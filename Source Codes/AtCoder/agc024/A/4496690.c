#include <stdio.h>
#include <stdlib.h>
#define FAIR (long long)(1e18)
typedef long long ll;

int main()
{
	ll a, b, c, k;
	ll ans;

	scanf("%lld %lld %lld %lld", &a, &b, &c, &k);

	if (k & 1) {
		ans = b - a;
	} else {
		ans = a - b;
	}

	if (llabs(a - b) > FAIR) {
		puts("Unfair");
	} else {
		printf("%lld\n", ans);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld %lld", &a, &b, &c, &k);
  ^