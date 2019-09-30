#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	printf("%d\n", (a * b < c * d) ? (c * d) : (a * b));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&a,&b,&c,&d);
  ^