#include<stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
#define invp(a,p)pom(a,p-2,p)
#define P 1000000007
ll fact[200010];

ll choose(n,r){
	return fact[n]*invp(fact[r]*fact[n-r],P)%P;
}

int main(){
	int h,w,a,b;
	scanf("%d%d%d%d",&h,&w,&a,&b);
	fact[0]=1;
	rep(i,1,200005)fact[i]=fact[i-1]*i%P;
	ll x=b-1,y=h-a;
	ll ans=0;
	while(x<w-1&&y>0){
		x++,y--;
		ans=(ans+choose(x+y,y)*choose((w-1-x)+(h-1-y),(h-1-y)))%P;
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘choose’:
./Main.c:9:4: warning: type of ‘n’ defaults to ‘int’ [-Wimplicit-int]
 ll choose(n,r){
    ^
./Main.c:9:4: warning: type of ‘r’ defaults to ‘int’ [-Wimplicit-int]
./Main.c: In function ‘main’:
./Main.c:15:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d%d",&h,&w,&a,&b);
  ^