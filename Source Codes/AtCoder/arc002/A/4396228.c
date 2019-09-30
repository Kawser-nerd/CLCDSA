#include <stdio.h>
int main (){
	int a=0;
	scanf("%d",&a);
	if(a%4==0)
	{
		if(a%100==0){
			if(a%400==0)
			{
				printf ("YES\n");
			}
			else
			{
				printf ("NO\n");
			}
			}
			else
			{
				printf ("YES\n");
			}
	}
	else
	{
		printf ("NO\n");
	}
	
	return 0;
	} ./Main.c: In function ‘main’:
./Main.c:4:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^