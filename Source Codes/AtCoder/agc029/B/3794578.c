#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define repp(i,l,r,k)for(ll i=(l);i<(r);i+=(k))
#define INF ((1LL<<62)-(1LL<<31))
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define bit(n,m)(((n)>>(m))&1)
int upll(const void*a, const void*b){return*(ll*)a<*(ll*)b?-1:*(ll*)a>*(ll*)b?1:0;}
int downll(const void*a, const void*b){return*(ll*)a<*(ll*)b?1:*(ll*)a>*(ll*)b?-1:0;}
void sortup(ll*a,int n){qsort(a,n,sizeof(ll),upll);}
void sortdown(ll*a,int n){qsort(a,n,sizeof(ll),downll);}
ll pom(ll a,ll n,int m){ll x=1;for(a%=m;n;n/=2)n&1?x=x*a%m:0,a=a*a%m;return x;}
//#define MOD 998244353
#define MOD 1000000007
#define invp(a,p)pom(a,p-2,p)

int cmp(const void*a,const void*b){
	ll aa=*(ll*)a;
	ll bb=*(ll*)b;
	ll aaa=aa&-aa;
	ll bbb=bb&-bb;
	if(aaa<bbb)return -1;
	if(aaa>bbb)return 1;
	if(aa<bb)return -1;
	return 1;
}

ll n,ans;
ll a[200010];
int flag[200010];
int nibutan(int l,int r,int x){
	//x?????????[l,r)???
	if(a[l]>x)return -1;
	while(r-l>1){
		int m=(l+r)/2;
		if(a[m]<x)l=m;
		else if(a[m]>x)r=m;
		else if(flag[m])r=m;
		else l=m;
	}
	return l;
}

int main(){
	scanf("%lld",&n);
	rep(i,0,n)scanf("%lld",a+i);
	qsort(a,n,sizeof(ll),cmp);
	for(int i=0;i<n;){
		int r=i;
		int t=a[i]&-a[i];
		while((a[r]&-a[r])==t)r++;
		//[i,r)?????
		for(int j=r-1;j>i;j--)if(!flag[j]){
			//a[j]??????????a[j]??????????2???X???X-a[j]??
			//???[i,j)?????????
			flag[j]=1;
			int x=1;
			while(x<=a[j])x+=x;
			int idx=nibutan(i,r,x-a[j]);
			if(idx!=-1&&a[idx]+a[j]==x&&!flag[idx]){
				ans++;
				flag[idx]=1;
			}
		}
		i=r;
	}
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:48:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%lld",&n);
  ^
./Main.c:49:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%lld",a+i);
            ^