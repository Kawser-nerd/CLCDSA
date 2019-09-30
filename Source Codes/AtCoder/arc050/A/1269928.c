#include <stdio.h>

int main(void)
{
	char c,C;
	scanf("%c %c",&C,&c);
	
	C=C+32;
	
	if(C==c){
		printf("Yes\n");
	} else{
		printf("No\n");
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %c",&C,&c);
  ^