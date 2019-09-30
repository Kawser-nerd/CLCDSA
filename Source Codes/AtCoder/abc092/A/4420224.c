#include <stdio.h>
int main(void){
	int a,b,c,d,m;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if(a<=b){
		if(c<=d) m=a+c;
		else m=a+d;
	}
	else{
		if(c<=d) m=b+c;
		else m=b+d;
	}
	printf("%d\n",m);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&a,&b,&c,&d);
  ^