#include<stdio.h>
int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	int number1,number2;
	number1 = a*b;
	number2 = c*d;
	if(number1 >= number2) printf("%d",number1);
	else printf("%d",number2);
	return 0;
 } ./Main.c: In function ‘main’:
./Main.c:5:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&a,&b,&c,&d);
  ^