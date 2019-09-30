#include <stdio.h>

int main(void)
{
	int a,b,n;
	
	scanf("%d %d %d",&n,&a,&b);
	
	if(a*n>=b){
		printf("%d\n",b);
	}else{
		printf("%d\n",a*n);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&n,&a,&b);
  ^