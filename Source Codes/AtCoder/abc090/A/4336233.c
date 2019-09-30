#include <stdio.h>

int main(void)
{
	int i,j;
	char c1[10],c2[10],c3[10];
	
	scanf("%s\n%s\n%s",c1,c2,c3);
	
	printf("%c%c%c\n",c1[0],c2[1],c3[2]);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s\n%s\n%s",c1,c2,c3);
  ^