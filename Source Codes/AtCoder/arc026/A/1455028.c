#include<stdio.h>
int main(){
	int a,b,c,d;
	scanf("%d %d %d",&a,&b,&c);
	d=a<5?a:5;
	a-=d;
	printf("%d\n",d*c+a*b);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^