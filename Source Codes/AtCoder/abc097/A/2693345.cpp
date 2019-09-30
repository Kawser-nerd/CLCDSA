#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

int main()
{
	int a,b,c,d;
	scanf("%d%d%d%d",&a,&b,&c,&d);
	if (abs(c - a) <= d || (abs(c - b) <= d && abs(b - a) <= d))
	{
		printf("Yes\n");
	}
	else
	{
		printf("No\n");
	}
	return 0;
}