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
	int w,a,b;
	scanf("%d%d%d",&w,&a,&b);
	if(a + w < b)	printf("%d\n", b - (a + w));
	else if(b + w < a)	printf("%d\n", a - (b + w));
	else printf("0\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&w,&a,&b);
  ^