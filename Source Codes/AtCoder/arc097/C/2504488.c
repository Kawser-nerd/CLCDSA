#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define max(p,q)((p)>(q)?(p):(q))
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

//B???+n
int bb[2][2010];
//bb[0][i]=Wi?????
int a[4010];
//a[i]=??i????
int tt[4010][2010];
//tt[i][j]=B1?Bj???Wi???????????

ll dp[4010][2010];
//dp[i][j]=i????W?j??????????
int main(){
	int n;
	scanf("%d\n",&n);
	rep(i,0,2*n){
		char c;int t;
		scanf("%c%d\n",&c,&t);
		a[i]=(c=='B')*n+t;
		bb[c=='B'][t]=i;
	}
	rep(i,1,n+1)rep(j,1,n+1)if(bb[0][i]>bb[1][j])tt[i][j]=1;
	rep(i,1,n+1)rep(j,1,n+1)if(bb[1][i]>bb[0][j])tt[n+i][j]=1;
	rep(i,1,n+n+1){
		rep(j,1,n+1){
			tt[i][j]+=tt[i][j-1];
//			printf("%lld ",tt[i][j]);
		}
//		puts("");
	}
	
	
	rep(i,0,n+n+1)rep(j,0,n+1)dp[i][j]=INF;
	dp[0][0]=0;
	
	rep(i,1,n+n+1)rep(j,max(i-n,0),n+1){
		if(j==0){
			//Bi?W1????
			dp[i][j]=dp[i-1][j]+tt[n+i][n];
		}else{
			//Wj?B(i-j+1)?????????
			//B(i-j)?W(j+1)???????
			dp[i][j]=min(dp[i-1][j-1]+tt[j    ][n]-tt[j    ][i-j],
						 dp[i-1][j  ]+tt[i-j+n][n]-tt[i-j+n][j]);
		}
	}
/*	rep(i,0,7){
		rep(j,0,4)printf("%lld ",dp[i][j]);
		puts("");
	}
	printf("%lld\n",dp[n+n][n]);
*/
	ll cnt=0;
	rep(kkk,0,2*n)rep(i,0,2*n-1)if(a[i]>a[i+1]){
		if(!((a[i]>n)^(a[i+1]>n)))cnt++;
		int t=a[i];a[i]=a[i+1];a[i+1]=t;
	}
	printf("%lld\n",dp[n+n][n]+cnt);
	
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d\n",&n);
  ^
./Main.c:25:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c%d\n",&c,&t);
   ^