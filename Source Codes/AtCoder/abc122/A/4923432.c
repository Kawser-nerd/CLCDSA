#include<stdio.h>
int main(void)
{
	char a;
	scanf("%s",&a);

	if (a=='A')	printf("T\n");
	
	else  if(a=='G') printf("C\n");
	
	else  if(a=='T') printf("A\n");
	
	else  if(a=='C') printf("G\n");
	

	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&a);
  ^