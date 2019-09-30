#include<stdio.h>
#include<math.h>
int main()
{
	int a;
	scanf("%d",&a);
	if(a==3||a==2||a==5)printf("Prime\n");
	else if(a==1)printf("Not Prime\n");
	else if(a%2==0||a%3==0||a%5==0)printf("Not Prime\n");
	else printf("Prime\n");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&a);
  ^