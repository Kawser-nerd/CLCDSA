#include<stdio.h>
int main(){
	int a,b;
	scanf("%d %d",&a,&b);
	printf("%d\n",18*60-a*60-b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^