#include <stdio.h>

int main(void)
{
	int a,b,c;
	int max=0;
	
	scanf("%d %d %d",&a,&b,&c);
	
	if(a>max){
		max=a;
	}
	if(b>max){
		max=b;
	}
	if(c>max){
		max=c;
	}
	
	printf("%d\n",a+b+c-max);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^