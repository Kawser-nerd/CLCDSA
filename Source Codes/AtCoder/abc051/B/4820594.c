#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define _CRT_SECURE_NO_WARNINGS
#define TLong long long

int main(int argc, char const *argv[])
{
	int k,s;
	int cnt = 0,z;
	scanf("%d%d",&k,&s);
	for (int x = 0; x <= k ; ++x)
	{
		for (int y = 0; y <= k; ++y){
			z = s - x - y;
			if(0 <= z && z <= k)	++cnt;
		}
	}
	printf("%d\n",cnt);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&k,&s);
  ^