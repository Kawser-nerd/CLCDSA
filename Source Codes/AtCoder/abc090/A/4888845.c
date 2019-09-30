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
	char s1[7],s2[7],s3[7];
	scanf("%s %s %s",s1,s2,s3);
	printf("%c%c%c",s1[0],s2[1],s3[2]);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %s %s",s1,s2,s3);
  ^