#include <stdio.h>

int main(void)
{
	int n;
	
	scanf("%d",&n);
	
	if(n%3==0){
		
		printf("YES\n");
	}else{
		printf("NO\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^