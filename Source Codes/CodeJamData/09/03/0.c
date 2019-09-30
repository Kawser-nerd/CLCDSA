#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define REP(i,a,b) for(i=a;i<b;i++)
#define rep(i,n) REP(i,0,n)

int main(){
  int i,j,k,l,m,n,len;
  int size,count=0;
  char in[10000];
  int dp[20];
  char *w="welcome to code jam";

  gets(in); size=atoi(in);
  while(size--){
    gets(in);
    for(i=0;;i++) if(in[i]<' ') break; len=i;
    rep(i,20) dp[i]=0; dp[0]=1;

    rep(i,len) for(k=18;k>=0;k--) if(w[k]==in[i]) dp[k+1]=(dp[k+1]+dp[k])%10000;

    printf("Case #%d: %04d\n",++count,dp[19]);
  }

  return 0;
}
