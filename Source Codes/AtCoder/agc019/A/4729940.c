#include <stdio.h>
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

typedef long long ll;

ll main()
{
	ll q, h, s, d;
	ll n;
	ll two = 1e9;
	ll one = 1e9;

	scanf("%lld %lld %lld %lld", &q, &h, &s, &d);
	scanf("%lld", &n);

	two = min(d, min(s * 2, min(h * 4, q * 8)));
	one = min(s, min(h * 2, q * 4));

	printf("%lld\n", (n / 2 * two) + (n % 2 * one));

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld %lld", &q, &h, &s, &d);
  ^
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld", &n);
  ^