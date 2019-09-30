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
  int N,M;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %d", &N, &M);


  int *K=(int *)malloc(sizeof(int)*N);
  int **A=(int **)malloc(sizeof(int *)*N);
  rep(i,N){
    A[i]=(int *)malloc(sizeof(int)*M);
  }
  rep(i,N){
    scanf("%d",&K[i]);
    rep(j,K[i]){
      scanf("%d",&A[i][j]);
      A[i][j]--;
    }
  }

  int **matrix=(int **)malloc(sizeof(int *)*N);
  rep(i,N){
    matrix[i]=(int *)malloc(sizeof(int)*M);
    rep(j,M){
      matrix[i][j]=0;
    }
  }

  rep(i,N){
    rep(j,K[i]){
      matrix[i][A[i][j]]++;
    }
  }

  int count=0;
  rep(j,M){
    int flag=1;
    rep(i,N){
      if(matrix[i][j]==0){
        flag=0;
      }
    }
    if(flag==1){
      count++;
    }
  }

  printf("%d\n", count);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:22:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:32:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&K[i]);
     ^
./Main.c:34:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&A[i][j]);
       ^