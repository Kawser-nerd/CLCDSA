#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))

ll a[100010];
ll m[100010];
ll p[100010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n)scanf("%lld",a+i);

	ll sum=0;
	rep(i,0,k)sum+=min(a[i],0);
	m[k-1]=sum;
	rep(i,k,n)m[i]=m[i-1]+min(a[i],0)-min(a[i-k],0);
	
	sum=0;
	rep(i,0,k)sum+=max(a[i],0);
	p[k-1]=sum;
	rep(i,k,n)p[i]=p[i-1]+max(a[i],0)-max(a[i-k],0);
	
	ll pp=0;
	rep(i,0,n)pp+=max(a[i],0);
	
	ll ans=pp;
	rep(i,k-1,n){
		ans=min(ans,p[i]);
		ans=min(ans,-m[i]);
	}
	printf("%lld\n",pp-ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:14:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^