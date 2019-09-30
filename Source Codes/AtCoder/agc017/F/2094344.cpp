#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<cmath>
#include<vector>
#include<map>
#include<set>
using namespace std;
#define ll long long
#define pb(x) push_back(x)
#define pr(x) cerr<<#x<<"="<<(x)<<endl
#define pri(x,lo) {cerr<<#x<<"={";for (int ol=0;ol<=lo;ol++)cerr<<x[ol]<<",";cerr<<"}"<<endl;}
#define N 1000
#define md 1000000007
int n,m,k,dp[2000010],sta,id,o,p,q,go[2000010][23],put[2000010],need1[30],need2[30],i,ans;
void add(int &x,int y){x+=y;if (x>md) x-=md;}
int main()
{
	scanf("%d %d %d",&n,&m,&k);n--;
	for (i=1;i<=k;i++)
	{
		scanf("%d %d %d",&o,&p,&q);o--;p--;
		need1[o]|=(1<<p);
		need2[o]|=(1<<p)*q;
	}
	memset(go,-1,sizeof(go));
	for (sta=0;sta<(1<<n);sta++)
	{
		id=0;
		for (i=0;i<n;i++)
			if (sta&(1<<i))
			{
				if (i>0&&!(sta&(1<<(i-1)))) go[sta][id]=sta^(1<<i)^(1<<(i-1));
				id++;
			}
	}
	memset(put,-1,sizeof(put));
	for (sta=0;sta<(1<<n);sta++)
		for (i=n-1;i>=0;i--)
			if ((sta&(1<<i))==0){put[sta]=sta^(1<<i);break;}
	dp[0]=1;
	for (i=0;i<m;i++)
	{
		for (sta=0;sta<(1<<n)-1;sta++)  add(dp[put[sta]],dp[sta]);
		for (int id=0;id<n;id++)
			for (int sta=(1<<n)-1;sta>=0;sta--)
			if (go[sta][id]!=-1) add(dp[go[sta][id]],dp[sta]);
		for (sta=0;sta<(1<<n);sta++) if ((sta&need1[i])!=need2[i]) dp[sta]=0;
	}
	for (sta=0;sta<(1<<n);sta++) add(ans,dp[sta]);
	printf("%d\n",ans);
	return 0;
}