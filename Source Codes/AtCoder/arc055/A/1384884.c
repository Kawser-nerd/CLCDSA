#include <stdio.h>
#include <stdlib.h>
#include <math.h>
 
int main ()
{
	int n;
	scanf("%d\n",&n);
	printf("1");
	for(int i;i<n-1;++i) printf("0");
	printf("7\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n",&n);
  ^