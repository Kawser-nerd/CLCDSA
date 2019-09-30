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
	int cntlen[17] = { 0 };
	int temp;
	for (int i = 0; i < 3; ++i)
	{
		scanf("%d",&temp);
		++cntlen[temp];
	}
	if(cntlen[5] == 2 && cntlen[7] == 1)	puts("YES");
	else puts("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&temp);
   ^