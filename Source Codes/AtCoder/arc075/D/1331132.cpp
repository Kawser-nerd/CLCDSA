#include<cstdio>
#include<map>
#include<iostream>
using namespace std;
typedef long long ll;
map<ll,ll>loe,ano,ple;
ll d,n=1,o,ans;
ll iabs(ll x)
{
	return x<0?-x:x;
}
ll dfs(ll use,ll rest)
{
	ll k=ple[(rest%10+10)%10];
	if(use<=0)
	{
		if(rest)
			return 0;
		else
			return 1+(o&1)*9;
	}
	if(k)
		return ano[k]*dfs(use/100,(rest-k*use)/10)+ano[k-10]*dfs(use/100,(rest+(10-k)*use)/10);
	else
		return ano[0]*dfs(use/100,rest/10);
}
ll logi(ll use,ll rest)
{
	ll k=ple[(rest%10+10)%10];
	if(use<=0)
	{
		if(rest)
			return 0;
		else
			return 1+(o&1)*9;
	}
	if(k)
		return loe[k]*dfs(use/100,(rest-k*use)/10)+loe[k-10]*dfs(use/100,(rest+(10-k)*use)/10);
	else
		return loe[0]*dfs(use/100,rest/10);
}
int main(void)
{
	for(ll i=-8; i<9; i++)
		loe[i]=9-iabs(i);
	for(ll i=-9; i<10; i++)
		ano[i]=10-iabs(i);
	for(ll i=0; i<10; i++)
		ple[i*9%10]=i;
	scanf("%lld",&d);
	for(int i=1;i<=18;i++)
	{
		o++;
		ans+=logi(n-1,d);
		n*=10;
	}
	cout<<ans;
}