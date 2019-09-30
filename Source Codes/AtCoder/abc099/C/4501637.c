#include <stdio.h>
#include <stdlib.h>//random,NULL
#include <string.h>
#include <time.h>
#include <unistd.h>//sleep()
#include <math.h>
#include <stdbool.h>

#define rep(i,n) for(int i=0; i<((int)n); i++)
#define REP(i,n) for(int i=0; i<=((int)n); i++)
#define srep(i,a,n) for(int i=a; i<((int)n); i++)
#define SREP(i,a,n) for(int i=a; i<=((int)n); i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)
#define RREP(i,n) for(int i=n; i>=0; i--)
#define INF 1000000000

int min(int a, int b){
  if(a>=b){
    return b;
  }
  else{
    return a;
  }
}

int solve(int N, int number, int *w, int *v){
  //dp[i]=????? i ?????????????????
  int *dp=(int *)malloc(sizeof(int)*(N+1));
  dp[0]=0;
  srep(i, 1, N+1){
    dp[i]=100000;
    rep(j,number){
      if(i-w[j]==0 || (i-w[j]>0 && dp[i-w[j]]!=0)){
        dp[i]=min(dp[i], dp[i-w[j]]+v[j]);
      }
    }
  }
  return dp[N];
}

int main(){
  char buf[1024];
  int N;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d", &N);

  int w[12];
  int v[12];
  w[0]=1;
  int degree=1;
  int number=1;
  while(pow(6,degree)<=N){
    w[number]=pow(6,degree);
    number++;
    degree++;
  }
  degree=1;
  while(pow(9,degree)<=N){
    w[number]=pow(9,degree);
    number++;
    degree++;
  }
  rep(i,number){
    v[i]=1;
  }

  // rep(i,number){
  //   printf("w[%d] = %d, v[%d] = %d\n", i, w[i], i, v[i]);
  // }
  // printf("number = %d\n", number);

  int ans=solve(N, number, w, v);

  printf("%d\n", ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:45:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^