#include "stdio.h"
 
int main()
{
	int in;
	float ans;
 
	scanf("%d", &in);
	ans = ((9.0/5.0)*in+32);
	printf("%f\n", ans);
 
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d", &in);
  ^