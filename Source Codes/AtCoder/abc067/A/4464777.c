#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{
	int a,b;
	scanf("%d%d",&a,&b);
	if(!(a % 3) || !(b % 3) || !((a + b) % 3))	printf("Possible\n");
	else printf("Impossible");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&a,&b);
  ^