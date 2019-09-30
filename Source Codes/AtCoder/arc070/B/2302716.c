#include <stdio.h>
#include <stdlib.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))

int dp1[5010][5010];
int dp2[5010][5010];
int a[5010];
int main(){
	int n,k;
	scanf("%d%d",&n,&k);
	rep(i,1,n+1)scanf("%lld",a+i);
	
	dp1[0][1]=1;
	//dp1[i][j]=a[1..i]?j-1??????
	rep(i,1,n+1){
		rep(x,0,5005)dp1[i][x]|=dp1[i-1][x];
		rep(x,0,max(0,5005-a[i]))dp1[i][x+a[i]]|=dp1[i-1][x];
	}
	//dp1[i][j]=[0..j)???a[1..i]??????????????
	rep(i,0,n)rep(x,1,5005)dp1[i][x]+=dp1[i][x-1];
	
	dp2[n+1][0]=1;
	//dp2[i][j]=a[i..n]?j??????
	for(ll i=n;i>=1;i--){
		rep(x,0,5005)dp2[i][x]|=dp2[i+1][x];
		rep(x,0,max(0,5005-a[i]))dp2[i][x+a[i]]|=dp2[i+1][x];
	}
	
	ll ans=0;
	rep(i,1,n+1){
		//a[i]?????
		//?a[i]?????[k-a[i],k)??????
		//?a[i+1..n]????x?a[1..i-1]????y?????x+y?[k-a[i],k)??????????
		//?a[i+1..n]????x?????a[1..i-1]?[k-a[i]-x,k-x)???????????
		rep(x,0,k)if(dp2[i+1][x]){
			if(dp1[i-1][max(0,k-x)]-dp1[i-1][max(0,k-x-a[i])]){
				ans++;
				break;
			}
		}
	}
	printf("%lld\n",n-ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:20: warning: format ‘%lld’ expects argument of type ‘long long int *’, but argument 2 has type ‘int *’ [-Wformat=]
  rep(i,1,n+1)scanf("%lld",a+i);
                    ^
./Main.c:12:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d",&n,&k);
  ^
./Main.c:13:14: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  rep(i,1,n+1)scanf("%lld",a+i);
              ^