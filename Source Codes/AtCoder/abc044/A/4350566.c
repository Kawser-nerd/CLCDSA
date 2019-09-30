#include <stdio.h>

int main(void)
{
	int n,k,x,y;
	
	scanf("%d\n%d\n%d\n%d",&n,&k,&x,&y);
	
	if(n<=k){
		printf("%d\n",n*x);
	}else{
		printf("%d\n",k*x+(n-k)*y);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%d\n%d\n%d",&n,&k,&x,&y);
  ^