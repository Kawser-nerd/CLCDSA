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

//????????????
//???????????????????????
//??????????????
//??????????????????????????????????
//?????????????????????????????????????????????????

//??????????????

int max(int a, int b){
  if(a>=b){
    return a;
  }
  else{
    return b;
  }
}


char min_char(char a, char b){
  int dif=a-b;
  if(dif>=0){
    return b;
  }
  else{
    return a;
  }
}

int max_char(int a, int b){
  int dif=a-b;
  if(dif<0){
    return b;
  }
  else{
    return a;
  }
}

int match(int a){
  if(a==1){
    return 2;
  }
  else if(a==7){
    return 3;
  }
  else if(a==4){
    return 4;
  }
  else if(a==2 || a==3 || a==5){
    return 5;
  }
  else if(a==6 || a==9){
    return 6;
  }
  else{
    return 7;
  }
}


int main(){
  char buf[1024];
  int N,M;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %d", &N, &M);

  int *A=(int *)malloc(sizeof(int)*M);
  rep(i,M){
    scanf("%d",&A[i]);
  }

  int *dp=(int *)malloc(sizeof(int)*(N+1));
  dp[0]=0;
  srep(i,1,N+1){
    dp[i]=-1;
  }

  srep(i,1,N+1){
    int res=0;
    rep(j,M){
      if(i-match(A[j])>=0 && dp[i-match(A[j])]!=-1){
        res=max(res, dp[i-match(A[j])]+1);
      }
    }
    if(res==0){
      ;
    }
    else{
      dp[i]=res;
    }
  }

  int digit=dp[N];

  int current=N;
  int *ans=(int *)malloc(sizeof(int)*digit);
  rrep(i,digit){
    int res=0;
    rep(j,M){
      int temp=current-match(A[j]);
      if(temp>=0 && temp!=-1 && dp[temp]==dp[current]-1){
        res=max(res, A[j]);
      }
    }
    ans[i]=res;
    current-=match(res);
  }

  rrep(i,digit){
    printf("%d", ans[i]);
  }
  printf("\n");

  return 0;

} ./Main.c: In function ‘main’:
./Main.c:81:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:86:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&A[i]);
     ^