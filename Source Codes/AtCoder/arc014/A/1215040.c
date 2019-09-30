#include <stdio.h>

int main(void)
{
	int n;
	scanf("%d",&n);
	
	if(n%2==0){
		printf("Blue\n");
	} else{
		printf("Red\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^