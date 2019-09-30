#include <stdio.h>
int main(void){
	int a,b,c;
	scanf("%d%d%d",&a,&b,&c);
	if(a+b<=b+c && a+b<=a+c) printf("%d\n",a+b);
	else if(b+c<=b+a && b+c<=c+a) printf("%d\n",b+c);
	else printf("%d\n",c+a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^