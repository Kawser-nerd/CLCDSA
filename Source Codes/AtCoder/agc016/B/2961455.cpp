#include<iostream>
#include<cstdio>
#define N 100100
using namespace std;

int n,mx,num[N];

inline bool pd(int u)
{
	int tt=0,i,cnt=0;
	bool have=0;
	for(i=1;i<=n;i++)
	{
		if(num[i]==u)
		{
			cnt++;
			continue;
		}
		if(u-num[i]>=2) return 0;
		tt++;
	}
	return u>=(tt+(!!cnt))&&u<=(tt+cnt/2);
}

int main()
{
	int i,j;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%d",&num[i]);
		mx=max(mx,num[i]);
	}
	if(pd(mx)||pd(mx+1))
	{
		puts("Yes");
	}
	else puts("No");
}