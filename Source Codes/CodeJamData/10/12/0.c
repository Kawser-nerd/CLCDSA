#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int ab(int x){if(x<0) return -x; return x;}

int dp[120][300];
int in[120], D, I, M, n;

int solve(int st,int bef){
  int i,j,k,res=1000000000,add,tmp;

  if(dp[st][bef] >= 0) return dp[st][bef];
  if(st==n) return dp[st][bef]=0;

  rep(i,256) if( ab(bef-in[st]) > ab(i-in[st]) ){
    add = ab(bef-i) - M; if(add < 0) add=0;
    k = solve(st,i) + I + add;
    if(res > k) res = k;
  }

  rep(i,256){
    add = ab(bef-i) - M; if(add<0) add=0;
    tmp = ab(i-in[st]);
    k = solve(st+1,i) + add + tmp;
    if(res > k) res = k;
  }

  k = solve(st+1,bef) + D;
  if(res > k) res = k;

  return dp[st][bef] = res;
}

int main(){
  int i,j,k,l,m,res;
  int size, count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d%d%d",&D,&I,&M,&n);
    rep(i,n) scanf("%d",in+i);

    rep(i,n+1) rep(j,256) dp[i][j]=-1;
    res = 1000000000;
    rep(i,n+1){
      k = solve(i,in[i]) + i*D;
      if(res > k) res = k;
    }
    printf("Case #%d: %d\n",++count,res);
  }

  return 0;
}
