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

/*
  ???
  10^9+7 ???????????????????????? 10^9+7 ???????????????????
  ??????????????????
  ???????????????????????????????????????
*/

int main(){
  char buf[100010];
  int N;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d", &N);

  char *s=(char *)malloc(sizeof(char)*N);

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%s", s);

  int *count=(int *)calloc(26, sizeof(int));
  rep(i,N){
    count[s[i]-'a']++;
  }

  int ans=1;
  rep(i,26){
    ans=((long)ans*(count[i]+1))%1000000007;
    //printf("%d\n", ans);
  }

  printf("%d\n", ans-1);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:28:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:33:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^