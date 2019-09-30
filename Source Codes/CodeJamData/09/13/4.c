#include <stdio.h>
#include <string.h>

typedef long long ll;
double dp[50];
int n,c;
ll binom[50][50];

/* we have "have" cards */
double calc(int have) {
   double res=0,nonew,prob;
   ll sum=0;
   int got;
   if(have==n) return 0.0;
   if(dp[have]>-.5) return dp[have];
   /* first, probability of getting 0 new cards */
   for(got=0;got<=c;got++) {
      if(have+got>n) break;
      // we got "got" new cards
      sum+=binom[have][c-got]*binom[n-have][got];
   }
   nonew=(double)binom[have][c]*binom[n-have][0]/sum;
   /* buy c cards */
   for(got=1;got<=c;got++) {
      if(got+have>n) break;
      /* probability of getting "got" new cards */
      prob=(double)binom[have][c-got]*binom[n-have][got]/sum;
//      printf("at %d cards: prob %f of getting %d new (%f)\n",have,prob,got,calc(have+got));
      res+=(1+calc(have+got))*prob;
   }
//   printf("%d %f (%f) (sum %I64d %I64d) %f\n",have,res,1-nonew,sum,binom[n][c],(res)/(1-nonew));
   return dp[have]=(nonew+res)/(1-nonew);
}

void bino() {
   int i,j;
   binom[0][0]=1;
   for(i=1;i<51;i++) {
      binom[i][0]=binom[i][i]=1;
      for(j=1;j<i;j++) binom[i][j]=binom[i-1][j-1]+binom[i-1][j];
   }
}

int main() {
   int cases,caseno=1;
   bino();
   scanf("%d",&cases);
   while(cases--) {
      memset(dp,-1,sizeof(dp));
      scanf("%d %d",&n,&c);
      printf("Case #%d: %.10f\n",caseno++,1+calc(c));
   }
   return 0;
}
