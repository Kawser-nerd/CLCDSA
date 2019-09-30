#include <stdio.h>
int main(void){
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if((a>b && b>c) || (c>b && b>a)) printf("%d\n",b);
	if((b>c && c>a) || (a>c && c>b)) printf("%d\n",c);
	if((c>a && a>b) || (b>a && a>c)) printf("%d\n",a);
	if(a==b && a!=c) printf("%d\n",a);
	if(b==c && b!=a) printf("%d\n",b);
	if(c==a && c!=b) printf("%d\n",c);
	if(a==b && b==c) printf("%d\n",a);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^