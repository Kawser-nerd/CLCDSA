#include <stdio.h>

int main(void)
{
	int a,b;
	
	scanf("%d %d",&a,&b);
	
	if(a<=8&&b<=8){
		printf("Yay!\n");
	}else{
		printf(":(\n");
	}
		return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d",&a,&b);
  ^