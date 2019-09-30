#include<stdio.h>
int main()
{
	char a,b;
	scanf("%c",&a);
	getchar();
	scanf("%c",&b);
	if(a=='H')
	{
		if(b=='H')
		printf("H");
		else
		printf("D");
	}
	else
	{
		if(b=='D')
		printf("H");
		else
		printf("D");
	}
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&a);
  ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&b);
  ^