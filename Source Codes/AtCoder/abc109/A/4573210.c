#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(int argc, char const *argv[])
{	
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a % 2 && b % 2)	printf("Yes\n");
	else printf("No\n");
} ./Main.c: In function ‘main’:
./Main.c:10:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^