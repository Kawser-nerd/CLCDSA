#include<stdio.h>
int main(void)
{
	char c1[3],c2[3],tmp;
	
	scanf("%s",c1);
	scanf("%s",c2);
	
	tmp=c2[0];
	c2[0]=c2[2];
	c2[2]=tmp;
	
	if(strcmp(c1,c2)==0) printf("YES");
	else printf("NO");
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: implicit declaration of function ‘strcmp’ [-Wimplicit-function-declaration]
  if(strcmp(c1,c2)==0) printf("YES");
     ^
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",c1);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",c2);
  ^