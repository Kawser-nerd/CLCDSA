#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <float.h>
#include <math.h>

#define max(X, Y) ((X) > (Y) ? (X) : (Y))
#define min(X, Y) ((X) < (Y) ? (X) : (Y))

typedef long long ll;

int main()
{
	ll a, b, c;

	scanf("%lld %lld %lld", &a, &b, &c);

	if (a + b >= (c - 1)) {
		printf("%lld\n", b + c);
	} else {
		printf("%lld\n", a + b + b + 1, c);
	}

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:10: warning: too many arguments for format [-Wformat-extra-args]
   printf("%lld\n", a + b + b + 1, c);
          ^
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld %lld %lld", &a, &b, &c);
  ^