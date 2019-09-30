#include<stdio.h>
int main()
{
	int a,b,c;
	while(scanf("%d%d%d",&a,&b,&c) != EOF)
	{
		int flag = 0;
		if(a + b == c) printf("Yes\n");
		else if(a + c == b) printf("Yes\n");
		else if(b + c == a) printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}