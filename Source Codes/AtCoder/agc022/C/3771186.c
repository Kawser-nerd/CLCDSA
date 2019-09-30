//O(N^4)??????????
//?i??????????????????????????a[i]?????????????
//?k??????????x??y???????O(N^3)?????????
//???????????O(1)???????????O(N^3)

#include <stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define bit(n,m)(((n)>>(m))&1)

int memo[60][60][60];//memo[i][j][k]=(k??????????i??j???????Yes??1?No??-1)

int f(int a,int b,int k){
	if(a<b)return -1;
	if(k==0)return a==b?1:-1;
	if(memo[a][b][k])return memo[a][b][k];

	int t=f(a,b,k-1);
	if(t==1)return memo[a][b][k]=1;
	t=f(a%k,b,k-1);
	if(t==1)return memo[a][b][k]=1;
	return memo[a][b][k]=-1;
}

int a[60],b[60];
ll d[60];//d[i]=(?????????????????????a[i]??????????????(bit))
int main(){
	int n;
	scanf("%d",&n);
	rep(i,0,n)scanf("%d",a+i);
	rep(i,0,n)scanf("%d",b+i);
	rep(i,0,n)d[i]=1LL<<a[i];
	
	rep(i,0,n)if(f(a[i],b[i],50)==-1){
		puts("-1");
		return 0;
	}
	
	ll ans=0;
	for(int k=50;k>0;k--){
		int flag=0;
		rep(i,0,n){
			int t=0;
			rep(j,0,51)if(bit(d[i],j)&&f(j,b[i],k-1)==1)t=1;
			if(t==0){
				flag=1;
				break;
			}
		}
		if(flag){
			ans|=1LL<<k;
			rep(i,0,n)rep(j,0,51)if(bit(d[i],j))d[i]|=1LL<<(j%k);
		}
	}
	printf("%lld",ans);
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d",&n);
  ^
./Main.c:30:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%d",a+i);
            ^
./Main.c:31:12: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,0,n)scanf("%d",b+i);
            ^