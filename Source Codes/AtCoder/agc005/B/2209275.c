#include<stdio.h>
#include<stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll a[200010];
ll left[200010],right[200010];

int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%lld",a+i);
	rep(i,0,n){
		ll temp=i-1;
		while(temp!=-1&&a[temp]>a[i])temp=left[temp];
		left[i]=temp;
	}
	for(int i=n-1;i>=0;i--){
		ll temp=i+1;
		while(temp!=n&&a[temp]>a[i])temp=right[temp];
		right[i]=temp;
	}
	ll ans=0;
	rep(i,0,n)ans+=a[i]*(i-left[i])*(right[i]-i);
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:14:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^