#include <stdio.h>

int main(void){

	char a[100],s[100],c[100];
	
	scanf("%s %s %s",a,s,c);
	
	printf("A%cC\n",s[0]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s %s %s",a,s,c);
  ^