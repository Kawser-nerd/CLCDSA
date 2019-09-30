#include<stdio.h>
int main()
{
	int a,b,c;
	scanf("%d %d %d",&a,&b,&c);
	printf("%d",(b/a)>c? c:(b/a));
 }