#include <stdio.h>
int main(void){
	int a,b,c,d;
	scanf("%d%d%d",&a,&b,&c);
	if(a==b)printf("%d\n",c);
	else if(b==c)printf("%d\n",a);
	else printf("%d\n",b);
	return 0;
} ./Main.c: In function �main�:
./Main.c:4:2: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&a,&b,&c);
  ^