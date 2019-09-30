#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

#define ll long long
#define INF 100000000000000000LL

int x,y;
ll dp[55][55][5], now, g, add;
ll s[55][55],w[55][55],t[55][55];

int main(){
  int i,j,k,l,m,n;
  int size,count=0;

  scanf("%d",&size);
  while(size--){
    scanf("%d%d",&x,&y);
    rep(i,x) rep(j,y) scanf("%lld%lld%lld",s[x-1-i]+j,w[x-1-i]+j,t[x-1-i]+j);
    rep(i,x) rep(j,y){
      t[i][j] = (-t[i][j])%(s[i][j]+w[i][j]);
      if(t[i][j]<0) t[i][j]+=s[i][j]+w[i][j];
    }

    rep(i,x) rep(j,y) rep(k,4) dp[i][j][k]=INF; dp[0][0][0]=0;
    for(;;){
      int fg=0;
      rep(i,x) rep(j,y){

        k=0; now=dp[i][j][k];
        if(i     && dp[i-1][j][2] > now+2) dp[i-1][j][2] = now+2, fg++;
        if(j     && dp[i][j-1][1] > now+2) dp[i][j-1][1] = now+2, fg++;
        g = (now+t[i][j]) % (s[i][j]+w[i][j]);
        if(g< s[i][j]) add=1; else add = s[i][j]+w[i][j]-g+1;
        if(dp[i][j][2] > now+add) dp[i][j][2] = now+add, fg++;
        if(g>=s[i][j]) add=1; else add = s[i][j]-g+1;
        if(dp[i][j][1] > now+add) dp[i][j][1] = now+add, fg++;
        
        k=1; now=dp[i][j][k];
        if(i     && dp[i-1][j][3] > now+2) dp[i-1][j][3] = now+2, fg++;
        if(j+1<y && dp[i][j+1][0] > now+2) dp[i][j+1][0] = now+2, fg++;
        g = (now+t[i][j]) % (s[i][j]+w[i][j]);
        if(g< s[i][j]) add=1; else add = s[i][j]+w[i][j]-g+1;
        if(dp[i][j][3] > now+add) dp[i][j][3] = now+add, fg++;
        if(g>=s[i][j]) add=1; else add = s[i][j]-g+1;
        if(dp[i][j][0] > now+add) dp[i][j][0] = now+add, fg++;
        
        k=2; now=dp[i][j][k];
        if(i+1<x && dp[i+1][j][0] > now+2) dp[i+1][j][0] = now+2, fg++;
        if(j     && dp[i][j-1][3] > now+2) dp[i][j-1][3] = now+2, fg++;
        g = (now+t[i][j]) % (s[i][j]+w[i][j]);
        if(g< s[i][j]) add=1; else add = s[i][j]+w[i][j]-g+1;
        if(dp[i][j][0] > now+add) dp[i][j][0] = now+add, fg++;
        if(g>=s[i][j]) add=1; else add = s[i][j]-g+1;
        if(dp[i][j][3] > now+add) dp[i][j][3] = now+add, fg++;
        
        k=3; now=dp[i][j][k];
        if(i+1<x && dp[i+1][j][1] > now+2) dp[i+1][j][1] = now+2, fg++;
        if(j+1<y && dp[i][j+1][2] > now+2) dp[i][j+1][2] = now+2, fg++;
        g = (now+t[i][j]) % (s[i][j]+w[i][j]);
        if(g< s[i][j]) add=1; else add = s[i][j]+w[i][j]-g+1;
        if(dp[i][j][1] > now+add) dp[i][j][1] = now+add, fg++;
        if(g>=s[i][j]) add=1; else add = s[i][j]-g+1;
        if(dp[i][j][2] > now+add) dp[i][j][2] = now+add, fg++;
        
      }
      if(!fg) break;
    }

    printf("Case #%d: %lld\n",++count,dp[x-1][y-1][3]);
  }

  return 0;
}
