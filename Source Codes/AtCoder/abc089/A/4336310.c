#include <stdio.h>

int main(void)
{
	int n,x;
	scanf("%d",&n);
	if(n%3==0){
		x=n/3;
	}else{
		x=(n-(n%3))/3;
	}
	
	printf("%d\n",x);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^