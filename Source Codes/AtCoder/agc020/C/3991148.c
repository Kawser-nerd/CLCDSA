#include <stdio.h>
#define ll long long
#define ull unsigned ll
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
ll a[2010];
ull s[40010];
ll sum;
int main()
{
	int n;
	scanf("%d",&n);
	rep(i,0,n){
		scanf("%lld",a+i);
		sum+=a[i];
	}
	s[0]=1;
	rep(i,0,n){
		for(int j=34000-a[i]/64;j>=0;j--){
			if(a[i]%64)s[j+a[i]/64+1]|=s[j]>>(64-a[i]%64);
			s[j+a[i]/64]|=s[j]<<(a[i]%64);
		}
	}
	for(ll ans=sum/2;;ans--)if(bit(s[ans/64],ans%64)){
		printf("%lld",sum-ans);
		return 0;
	}
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",a+i);
   ^