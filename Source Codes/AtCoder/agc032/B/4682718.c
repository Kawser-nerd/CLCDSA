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

  if(N%2==1){
    int M=N*(N-1)/2-(N-1)/2;
    printf("%d\n", M);
    srep(i,1,N+1){
      srep(j,i+1,N+1){
        if(i+j!=N){
          printf("%d %d\n", i, j);
        }
      }
    }
  }

  else{
    int M=N*(N-1)/2-N/2;
    printf("%d\n", M);
    srep(i,1,N+1){
      srep(j,i+1,N+1){
        if(i+j!=N+1){
          printf("%d %d\n", i, j);
        }
      }
    }
  }


  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^