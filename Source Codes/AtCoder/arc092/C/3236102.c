#include<stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define max(p,q)((p)>(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

ll n;
ll a[1010];
ll e,o;
ll M=-INF,Mi;
ll ans[1010],anscnt;

void del(ll n){
	//-1???
	ll i=0;
	while(a[0]==-1){
		ans[anscnt++]=0;
		rep(i,0,n)a[i]=a[i+1];
		n--;
	}
	while(a[n-1]==-1){
		ans[anscnt++]=n-1;
		a[n-1]=0;
		n--;
	}
	ll flag=1;
	while(flag){
//		rep(i,0,n)printf("%d ",a[i]);printf("%d\n",n);
		flag=0;
		for(ll i=1;i<n-1;i++)if(a[i]==-1&&a[i-1]==a[i+1]){
			ans[anscnt++]=i;
			rep(j,i-1,n)a[j]=a[j+2];		
			n-=2;
			flag=1;
		}
	}
}

int main(){
	scanf("%lld",&n);
	//????????????
	//oxoxxxo?x?1??????2??????????2?????(n-1)/2???????????
	rep(i,0,n){
		ll t;
		scanf("%lld",&t);
		if(t>M)M=t,Mi=i;
		if(t>0){
			a[i]=1;
			if(i%2)o+=t;
			else e+=t;
		}else{
			a[i]=-1;
		}
	}
	
	if(M<=0){
		printf("%lld\n%lld\n",M,n-1);
		for(ll i=n-1;i>Mi;i--)printf("%lld\n",i+1);
		rep(i,0,Mi)printf("%lld\n",1);
	}else{
		if(o>e)repp(i,0,n,2)a[i]=-1;
		else repp(i,1,n,2)a[i]=-1;
		del(n);
		printf("%lld\n%lld\n",max(e,o),anscnt);
		rep(i,0,anscnt)printf("%lld\n",ans[i]+1);
	}
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:60:21: warning: format ‘%lld’ expects argument of type ‘long long int’, but argument 2 has type ‘int’ [-Wformat=]
   rep(i,0,Mi)printf("%lld\n",1);
                     ^
./Main.c:41:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:46:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%lld",&t);
   ^