#include <stdio.h>
#include<string.h>


int main(void)
{
	int n,a,b,sum;
	scanf("%d %d %d",&n,&a,&b);
	
	if(n<=5){
		printf("%d\n",b*n);
	} else{
		printf("%d\n",b*5+(n-5)*a);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&n,&a,&b);
  ^