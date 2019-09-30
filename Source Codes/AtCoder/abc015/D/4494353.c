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

int max(int a, int b){
  if(a>=b){
    return a;
  }
  else{
    return b;
  }
}

//????????
//???????????????????????
//??????????????????? ~O(N*limit)??????

//???????????????????????
int solve(int N, int limit_w, int limit_n, int *w, int *v);
//????????????????????????????????????????????????????????????
int search(int N, int number, int left_w, int left_n, int *w, int *v, int ***dp);


int solve(int N, int limit_w, int limit_n, int *w, int *v){
  int ***dp=(int ***)malloc(sizeof(int **)*N);
  rep(i,N){
    dp[i]=(int **)malloc(sizeof(int *)*(limit_w+1));
    rep(j,limit_w+1){
      dp[i][j]=(int *)malloc(sizeof(int)*(limit_n+1));
      rep(k,limit_n+1){
        dp[i][j][k]=-1;
      }
    }
  }

  return search(N, 0, limit_w, limit_n, w, v, dp);
}

int search(int N, int number, int left_w, int left_n, int *w, int *v, int ***dp){
  //number???????????left_w,left_n??????????????????
  if(number==N || left_n==0){
    //printf("a\n");
    return 0;
  }

  else if(dp[number][left_w][left_n]!=-1){
    //printf("b\n");
    //number?????left????????????????????
    return dp[number][left_w][left_n];
  }

  else if(w[number]>left_w){
    //printf("c\n");
    int res=search(N, number+1, left_w, left_n, w, v, dp);
    dp[number][left_w][left_n]=res;
    return res;
  }

  else{
    //printf("d\n");
    //i???????????????????????????
    int choose=search(N, number+1, left_w-w[number], left_n-1, w, v, dp)+v[number];
    int non_choose=search(N, number+1, left_w, left_n, w, v, dp);
    int res=max(choose, non_choose);
    dp[number][left_w][left_n]=res;
    return res;
  }
}


int main(){
  char buf[1024];
  int W, N, K;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d", &W);

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %d", &N, &K);

  int *w=(int *)malloc(sizeof(int)*N);
  int *v=(int *)malloc(sizeof(int)*N);
  rep(i,N){
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf, "%d %d", &w[i], &v[i]);
  }

  int ans=solve(N, W, K, w, v);

  printf("%d\n", ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:87:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:90:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:96:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf,sizeof(buf),stdin);
     ^