#include<iostream>
#include<cstdio>
#include<algorithm>
#define N 100100
using namespace std;

int n,num[N];

inline bool cmp(int u,int v)
{
	return u>v;
}

int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
	}
	sort(num+1,num+n+1,cmp);
	for(i=1;i<=n;i++)
	{
		if(i>num[i]) break;
	}
	i--;
	if((num[i]-i)&1)
	{
		puts("First");
		return 0;
	}
	for(j=i+1;num[j]==i;j++);
	j--;
	if((j-i)&1)
	{
		puts("First");
		return 0;
	}
	puts("Second");
}