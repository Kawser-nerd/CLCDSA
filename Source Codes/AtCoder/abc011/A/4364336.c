#include <stdio.h>

int main(void)

{
	int n;
	
	scanf("%d",&n);
	
	if(n==12){
		printf("1\n");
	}else{
		printf("%d\n",n+1);
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^