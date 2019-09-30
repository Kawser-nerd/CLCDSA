#include<iostream>
#include<cstdio>
#include<map>
#include<cmath>
#define ll long long
#define N 100100
#define MZ 1300
using namespace std;
 
ll n,a[N],b[N],zs[N],zz,ans;
bool P[N];
map<ll,ll>cnt;
map<ll,bool>vis;
 
inline void get()
{
	ll i,j;
	for(i=2;i<=100000;i++)
	{
		if(!P[i]) zs[++zz]=i;
		for(j=1;j<=zz&&zs[j]*i<=100000;j++) P[zs[j]*i]=1;
	}
}
 
int main()
{
//	freopen("2.txt","r",stdin);
	ll i,j,k,p,q,t,tmp;
	get();
//	cout<<zs[1300];
	cin>>n;
	for(i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
	}
	for(i=1;i<=n;i++)
	{
		t=a[i];
		b[i]=q=1;
		for(j=1;j<=MZ&&t!=1;j++)
		{
			p=0;
			for(;t%zs[j]==0;t/=zs[j]) p++;
			p%=3;
			if(!p) continue;
			for(k=1;k<=p;k++) q*=zs[j];
			for(k=p+1;k<=3;k++) b[i]*=zs[j];
		}
		if(t)
		{
			tmp=sqrt(t);
			if(tmp*tmp==t)
			{
				q*=t;
				b[i]*=tmp;
			}
			else
			{
				q*=t;
				b[i]*=t*t;
			}
		}
		a[i]=q;
		cnt[a[i]]++;
//		if(i%1000==0) cout<<i<<endl;
	}
//	return 0;
//	for(i=1;i<=n;i++) cout<<a[i]<<" ";puts("");
//	for(i=1;i<=n;i++) cout<<b[i]<<" ";puts("");
	for(i=1;i<=n;i++)
	{
		if(vis[a[i]] || vis[b[i]] || a[i]==1) continue;
		vis[a[i]]=1;
		ans+=max(cnt[a[i]],cnt[b[i]]);
	}
	cout<<ans+(!!cnt[1]);
}