#include <stdio.h>

int main(void)
{
	char a,b;
	
	scanf("%c %c",&a,&b);
	
	if(a!=b){
		printf("D\n");
	}else{
		printf("H\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %c",&a,&b);
  ^