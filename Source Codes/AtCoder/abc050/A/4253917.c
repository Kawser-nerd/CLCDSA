#include<stdio.h>
int main() {
	int a,b;
	char fu;
	scanf("%d %c %d",&a,&fu,&b);
	if(fu=='+')
		printf("%d",a+b);
	else
		printf("%d",a-b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %c %d",&a,&fu,&b);
  ^