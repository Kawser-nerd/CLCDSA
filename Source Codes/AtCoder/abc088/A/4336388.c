#include <stdio.h>

int main(void)
{
	int a,n;
	scanf("%d\n%d",&n,&a);
	
	if(n%500-a<=0){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n%d",&n,&a);
  ^