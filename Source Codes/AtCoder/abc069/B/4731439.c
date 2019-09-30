#include<stdio.h>
#include<string.h>
int main(void){
	
	char s[100];
	
	scanf("%s",s);
	int i=strlen(s);
	
	
	
	printf("\n%c%d%c\n\n",s[0],i-2,s[i-1]);
	
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",s);
  ^