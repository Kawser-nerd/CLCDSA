#include<stdio.h>

int main(void) {
	int i,n,sum=0;
	scanf("%d",&n);
	printf("%d\n",n*800-((n/15)*200));
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^