#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int n, g;
double c[50][50];
double dp[50];

double solve(int r){
  int i,j,k; double res=0, p=0, tmp;

  if(dp[r]>-0.5) return dp[r];

  REP(i,1,g+1){
    tmp = c[n-r][g-i] * c[r][i] / c[n][g];
    if(r-i>=0) res += tmp * solve(r-i), p+=tmp;
  }
  res=(res+1)/p;

  return dp[r]=res;
}

int main(){
  int i,j,k,l,m;
  int size,count=0;
  double res;

  c[0][0]=1; REP(j,1,50) c[0][j]=0;
  REP(i,1,50){
    c[i][0]=1; REP(j,1,50) c[i][j]=c[i-1][j-1]+c[i-1][j];
  }

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&n,&g);
    rep(i,n+1) dp[i]=-1; dp[0]=0;
    res=solve(n);
    printf("Case #%d: %.8lf\n",++count,res);
  }

  return 0;
}
