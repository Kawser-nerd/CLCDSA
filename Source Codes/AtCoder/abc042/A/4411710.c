#include<stdio.h>
 
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	if(a+b+c==17 && a*b+b*c+c*a==95 && a*b*c==175)
		printf("YES");
	else printf("NO");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d %d %d",&a,&b,&c);
  ^