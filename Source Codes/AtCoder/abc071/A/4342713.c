#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int x,a,b;
	
	scanf("%d %d %d",&x,&a,&b);
	
	if(abs(a-x)<abs(b-x)){
		printf("A\n");
	}else{
		printf("B\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&x,&a,&b);
  ^