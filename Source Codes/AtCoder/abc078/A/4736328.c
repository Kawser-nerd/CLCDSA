#include<stdio.h>
int main(void)
{
	char x,y;
	
	scanf("%c %c",&x,&y);
	
	if((int)(x)<(int)(y)) printf("<");
	else if((int)(x)>(int)(y)) printf(">");
	else printf("=");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c %c",&x,&y);
  ^