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

//XOR?????????? 0,1 ????????????????????
//???????1???????????X??????????????

int main(){
  char buf[1024];
  int N;
  long K;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %ld", &N, &K);

  long *A=(long *)malloc(sizeof(long)*N);
  rep(i,N){
    scanf("%ld",&A[i]);
  }

  int K_digit;
  rrep(i,40){
    //(1<<i)???????????i?????31
    if(K&(1ull<<i)){
      K_digit=i;
      break;
    }
  }

  int *count=(int *)calloc(40, sizeof(int));
  rep(i,40){
    rep(j,N){
      if(A[j]&(1ull<<i)){
        count[i]++;
      }
    }
  }

  // rep(i,40){
  //   printf("count[%d] = %d\n", i, count[i]);
  // }
  // printf("K_digit = %d\n", K_digit);

  bool sick_to_top=1;
  RREP(i,K_digit){
    if(sick_to_top==1){
      if(K&(1ull<<i)){
        if(count[i]<(N+1)/2){
          //printf("1\n");
          count[i]=N-count[i];
        }
        else{
          //printf("2\n");
          sick_to_top=0;
        }
      }
      else{
        //printf("3\n");
        ;
      }
    }
    else{
      if(count[i]<(N+1)/2){
        //printf("4\n");
        count[i]=N-count[i];
      }
      else{
        //printf("5\n");
        ;
      }
    }
  }

  long ans=0;
  rep(i,40){
    ans+=(long)count[i]*(1ull<<i);
  }

  printf("%ld\n", ans);

  return 0;

} ./Main.c: In function ‘main’:
./Main.c:25:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:30:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld",&A[i]);
     ^