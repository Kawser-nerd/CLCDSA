#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define M 8000000
#define INF 1000000000

void intSort(int d[],int s){int i=-1,j=s,k,t;if(s<=1)return;k=(d[0]+d[s-1])/2;for(;;){while(d[++i]<k);while(d[--j]>k);if(i>=j)break;t=d[i];d[i]=d[j];d[j]=t;}intSort(d,i);intSort(d+j+1,s-j-1);}
int dp[M];

int main(){
  int i,j,k,l,m,n;
  ll L, res;
  int in[120];
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest %d\n",size);
    scanf("%lld%d",&L,&n);
    rep(i,n) scanf("%d",in+i);
    intSort(in,n);

    rep(i,M) dp[i]=INF; dp[0]=0;
    rep(k,n) REP(i,in[k],M) if(dp[i]>dp[i-in[k]]+1) dp[i]=dp[i-in[k]]+1;

    res = (L-M)/in[n-1];
    L -= res*in[n-1];
    while(L>=M) L-=in[n-1], res++;

    printf("Case #%d: ",++count);
    if(dp[L]==INF){ puts("IMPOSSIBLE"); continue; }
    printf("%lld\n",res + dp[L]);
  }

  return 0;
}
