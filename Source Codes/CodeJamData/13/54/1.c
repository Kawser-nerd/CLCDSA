#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

double dp[1111111];

double solve(int mask, int n){
  int i,j,k,st,cur,wait;
  double res = 0;
  if(dp[mask] > -0.1) return dp[mask];

  rep(i,n) if(!(mask & (1<<i))) break;
  if(i==n) return dp[mask] = 0;

  k = st = i;
  wait = 0;
  rep(i,n){
    cur = (st-i+n)%n;
    if(!(mask&(1<<cur))) k = cur, wait = 0;
    else                 wait++;

    res += solve(mask | (1<<k), n) + n - wait;
  }
  res /= n;

  return dp[mask] = res;
}

int main(){
  int i,j,k,l,m,n;
  int size, count = 0;
  int mask;
  double res;
  char in[1000];

  scanf("%d",&size);
  while(size--){
    fprintf(stderr,"rest %d\n",size);
    scanf("%s",in);
    n = strlen(in);
    mask = 0;
    rep(i,n) if(in[i]=='X') mask |= (1<<i);

    rep(i,1<<n) dp[i] = -1;
    res = solve(mask,n);

    printf("Case #%d: %.15f\n",++count,res);
  }

  return 0;
}
