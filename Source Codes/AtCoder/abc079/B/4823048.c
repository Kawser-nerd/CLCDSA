#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long
#define TBMod 1000000007

int main(int argc, char const *argv[])
{
	TLong n;
	TLong tb[90] = {0};
	tb[0] = 2;	tb[1] = 1;
	for (int i = 2; i <= 86; ++i)	tb[i] = tb[i - 1] + tb[i - 2];
	scanf("%lld",&n);
	printf("%lld\n", tb[n]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^