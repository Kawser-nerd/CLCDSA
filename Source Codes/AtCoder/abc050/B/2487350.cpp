#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
#define N 100010
using namespace std;

ll l,last,ans,a,b,n,m,num[N],sum;

int main()
{
	ll i,j,p,q;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&num[i]);
		sum+=num[i];
	}
	cin>>m;
	for(i=1;i<=m;i++)
	{
		scanf("%lld%lld",&p,&q);
		printf("%lld\n",sum+q-num[p]);
	}
}