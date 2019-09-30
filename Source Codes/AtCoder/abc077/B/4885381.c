#include<math.h>
#include<stdio.h>//sqrtN
int main(void)
{
	int n,i;
	scanf("%d",&n);
	i=sqrt(n);
	printf("%d\n",i*i);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^