#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n;
int a[100100];
int ma,mi=0x3f3f3f3f;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)scanf("%d",&a[i]),ma=max(ma,a[i]),mi=min(mi,a[i]);
	if(ma-mi>=2)
	{
		puts("No");
		return 0;
	}
	int c=0;
	if(ma==mi)
	{
		if(mi==n-1||mi*2<=n)
			puts("Yes");
		else puts("No");
	}
	else
	{
		for(int i=1;i<=n;++i)
			if(a[i]==mi)c++;
		if(2*(mi+1-c)>n-c||ma-c<=0)
			puts("No");
		else puts("Yes");
	}
	return 0;
}