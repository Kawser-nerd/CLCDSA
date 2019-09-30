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


int main(){
  char buf[1024];
  int N;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d", &N);

  int *C=(int *)malloc(sizeof(int)*(N+1));
  C[0]=0;
  srep(i,1,N+1){
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf, "%d", &C[i]);
  }

  long *dp=(long *)calloc(N+1, sizeof(long));
  dp[0]=1;

  //?j????????????????????
  long *memo=(long *)calloc(200001, sizeof(long));

  srep(i,1,N+1){
    if(C[i]==C[i-1]){
      dp[i]=(dp[i]+dp[i-1])%1000000007;
    }
    else{
      dp[i]=(dp[i]+dp[i-1])%1000000007;
      dp[i]=(dp[i]+memo[C[i]])%1000000007;
      memo[C[i]]=(memo[C[i]]+dp[i-1])%1000000007;
    }
  }

  // rep(i,N+1){
  //   printf("dp[%d] = %ld\n", i, dp[i]);
  // }

  printf("%ld\n", dp[N]);


  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:28:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf,sizeof(buf),stdin);
     ^