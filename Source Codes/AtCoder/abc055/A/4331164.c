#include<stdio.h>
int main()
{
	int m;
	scanf("%d",&m);
	int number = m / 15;
	printf("%d",m*800-200*number);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&m);
  ^