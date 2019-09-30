#include<stdio.h>
#include<string.h>
int main(void)
{
	char n[2];
	
	scanf("%s",n);
	
	if(strchr(n,'9')!=0) printf("Yes");
	else printf("No");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",n);
  ^