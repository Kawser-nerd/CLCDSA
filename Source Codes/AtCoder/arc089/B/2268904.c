#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

#define f(xl,xr,yl,yr)(s[xr][yr]-s[xl][yr]-s[xr][yl]+s[xl][yl])

ll s[1010][2010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,0,n){
		int x,y;
		char c;
		scanf("%d%d %c",&x,&y,&c);
		ll d=x/k+y/k;
		s[x%k+1][y%k+(((d%2)^(c=='B'))?k:0)+1]++;
	}
	rep(x,0,k+5)rep(y,1,2*k+5)s[x][y]+=s[x][y-1];
	rep(y,0,2*k+5)rep(x,1,k+5)s[x][y]+=s[x-1][y];
	//s[x][y]??[0,x)*[0,y)??
	
	ll sum=s[k][2*k];
	ll ans=0;
	rep(x,0,k)rep(y,0,k){
		//[x,x+k)*[y,y+k)???????????????3?????????
		//[x,k)*[y,y+k)
		//[0,x)*([0,y)+[y+k,2*k))
		//y>=k??????sum????
		ll t1=f(x,k,y,y+k);
		ll t2=f(0,x,0,y);
		ll t3=f(0,x,y+k,2*k);
		ans=max(ans,max(t1+t2+t3,sum-t1-t2-t3));
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:17:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d %c",&x,&y,&c);
   ^