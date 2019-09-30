#include<cstdio>
int main()
{
	int x,b,a;
	scanf("%d%d%d",&x,&a,&b);
	if (b<=a) printf("delicious\n");
	else if (b<=a+x) printf("safe\n");
	else printf("dangerous\n");
}