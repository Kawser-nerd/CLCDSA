#include<stdio.h>
#define ll long long
#define rep(i,l,r)for(ll i=(l);i<(r);i++)
#define min(p,q)((p)<(q)?(p):(q))
#define INF ((1LL<<62)-(1LL<<31))

//next_permutation
void nexp(ll*a,int cnt){
	int l=cnt-1,r=cnt-1;
	ll t;
	while(--l>=0&&a[l]>a[l+1]);
	if(l>=0){
		while(a[l]>a[r])r--;
		t=a[l];a[l]=a[r];a[r]=t;
	}
	for(l++,r=cnt-1;l<r;l++,r--)t=a[l],a[l]=a[r],a[r]=t;
}

ll cost[210][210];
ll dddd[210][210];
 
void waasharuhuroido(ll n){
	rep(i,0,n)rep(j,0,n)dddd[i][j]=i==j?0:cost[i][j]?cost[i][j]:INF;
	rep(k,0,n)rep(i,0,n)rep(j,0,n)dddd[i][j]=min(dddd[i][j],dddd[i][k]+dddd[k][j]);
}
 
int main(){
	int n,m,r,rr[10];
	scanf("%d%d%d",&n,&m,&r);
	rep(i,0,r){
		int t;
		scanf("%d",&t);
		t--;
		rr[i]=t;
	}
	rep(i,0,m){
		int a,b,c;
		scanf("%d%d%d",&a,&b,&c);
		a--;b--;
		cost[a][b]=cost[b][a]=c;
	}
	waasharuhuroido(n);
	ll ans=INF,c=1;
	rep(i,1,r+1)c*=i;
	ll index[10]={0,1,2,3,4,5,6,7,8,9};
	rep(nnnn,0,c){
		int t=0;
		rep(i,1,r)t+=dddd[rr[index[i-1]]][rr[index[i]]];
		ans=min(ans,t);
		nexp(index,r);
	}
	printf("%lld\n",ans);
	return 0;
} ./Main.c: In function ‘main’:
./Main.c:29:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%d%d%d",&n,&m,&r);
  ^
./Main.c:32:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&t);
   ^
./Main.c:38:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d",&a,&b,&c);
   ^