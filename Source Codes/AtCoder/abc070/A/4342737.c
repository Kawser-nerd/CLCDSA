#include <stdio.h>

int main(void)

{
	char n[100];
	
	scanf("%s",n);
	
	if(n[0]==n[2]){
		printf("Yes\n");
	}else{
		printf("No\n");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",n);
  ^