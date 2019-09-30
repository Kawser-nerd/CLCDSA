#include <stdio.h>
#define DIV 1000000007
int main(){
  char c;
  long long int dp[5]={0,1,0,0,0};

  while((c=getchar())!='\n')
    if(c=='?')
      for(int j=4;j>0;j--)
	dp[j]=(dp[j]*3+dp[j-1])%DIV;
    else
      dp[c-'A'+2]=(dp[c-'A'+2]+dp[c-'A'+1])%DIV;

  printf("%lld\n",dp[4]);

  return 0;
}