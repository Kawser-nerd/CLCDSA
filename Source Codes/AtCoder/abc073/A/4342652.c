#include <stdio.h>

int main(void)
{
	char no[100];
	
	scanf("%s",no);
	
	if(no[0]!='9'&&no[1]!='9'){
		printf("No\n");
	}else{
		printf("Yes\n");
	}
	
	return 0;
	
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",no);
  ^