#include <stdio.h>

int main(void)
{
	int a,b,c,d,sum;
	scanf("%d\n%d\n%d\n%d",&a,&b,&c,&d);
	
	if(a>b){
		if(c>d){
			sum=b+d;
		}else{
			sum=b+c;
		}
	}else{
		if(c>d){
			sum=a+d;
		}else{
			sum=a+c;
		}
	}
	
	printf("%d\n",sum);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%d\n%d\n%d",&a,&b,&c,&d);
  ^