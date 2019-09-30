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
	int n,k;
	int pat;
	scanf("%d%d",&n,&k);
	pat = k;
	for (int i = 1; i < n; ++i)	pat *= (k - 1);
	printf("%d\n", pat);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^