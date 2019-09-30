#include <stdio.h>

int main(void)
{
	int a,b,c,money;
	scanf("%d %d %d",&a,&b,&c);
	if(a>b&&a>c){
		money=a*10+b+c;
	}else if(b>c){
		money=b*10+a+c;
	}else{
		money=c*10+a+b;
	}
	
	printf("%d",money);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^