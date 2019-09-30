#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>
#define ll long long
#define ull unsigned long long

#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))

#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll d[300010];
ll n,cnt;
void f(ll a,ll b,ll l,ll r,ll s){
	//[l,r)?inc?a,dec?b???????s+1????????
	if(a==0||b==0){
		puts("-1");
		exit(0);
	}
	if(cnt+a<=n){
		rep(j,0,a)d[r-1-j]=s+a-j;
		cnt+=a;
		if(cnt+b-1<=n){
			rep(i,0,b-1)d[l+i]=s+a+b-1-i;
			cnt+=b-1;
		}else{
			for(ll i=r-a-1;i>=l;i--)d[i]=s+r-i;
			cnt=n;
		}
	}else{
		rep(j,0,n-cnt)d[l+j]=s+1+j;
		cnt=n;
	}
//	printf("%lld %lld %lld %lld %lld\n",a,b,l,r,s);
//	rep(i,0,16)printf("%lld ",d[i]);puts("");
	if(n!=cnt)f(a-1,b-1,l+b-1,r-a,s+a+b-1);
}

int main(){
	ll a,b;
	scanf("%lld%lld%lld",&n,&a,&b);
	if(a+b>n+1){
		puts("-1");
		return 0;
	}
	f(a,b,0,n,0);
	rep(i,0,n)printf("%lld ",d[i]);
	puts("");
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:44:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld%lld%lld",&n,&a,&b);
  ^