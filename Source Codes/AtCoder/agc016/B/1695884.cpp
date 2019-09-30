#include<cstdlib>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
int n,maxx=-1,minn=1e9;
int a[100010],num[100010];
bool flag=0;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		num[a[i]]++;
		maxx=max(maxx,a[i]);
		minn=min(minn,a[i]);
		if(a[i]!=a[i-1]&&i>=2)flag=1;
	}
	if(maxx-minn>1){printf("No");return 0;}
	if(flag)
	{
		if(2*(maxx-num[minn])<=num[maxx]&&maxx>num[minn])printf("Yes");
		else printf("No");
	}
	else
	{
		int x=a[1];
		if(x==1||x==n-1||x==n/2)printf("Yes");
		else printf("No");
	}
	return 0;
}