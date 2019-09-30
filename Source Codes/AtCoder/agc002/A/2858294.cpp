#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;

int main()
{
	int a,b;
	scanf("%d %d",&a,&b);
	if(a>0 && b>0)
	{
		printf("Positive");
	}
	else if(a<=0 && b>=0)
	{
		printf("Zero");
	}
	else if(a<0 && b<0 && (a-b)%2==0)
	{
		printf("Negative");
	}
	else
	{
		printf("Positive");
	}
	return 0;
}