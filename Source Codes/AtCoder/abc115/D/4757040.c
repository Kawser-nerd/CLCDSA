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


long dfs(int index, long left, long *Lv_n, long *Lv_p);


int main(){
  char buf[1024];
  int N;
  long X;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %ld", &N, &X);

  //Lv(n)???
  long *Lv_n=(long *)malloc(sizeof(long)*(N+1));
  Lv_n[0]=1;
  srep(i,1,N+1){
    Lv_n[i]=Lv_n[i-1]*2+3;
  }

  //Lv_n???????
  long *Lv_p=(long *)malloc(sizeof(long)*(N+1));
  Lv_p[0]=1;
  srep(i,1,N+1){
    Lv_p[i]=Lv_p[i-1]*2+1;
  }


  long pathy=dfs(N, X, Lv_n, Lv_p);

  printf("%ld\n", pathy);

  return 0;
}



//???left??????????????????
long dfs(int index, long left, long *Lv_n, long *Lv_p){
  long res;
  if(left==0){
    //printf("1\n");
    res=0;
  }
  else if(index==0){
    //printf("2\n");
    res=1;
  }
  else{
    long temp=Lv_n[index-1]+2;
    if(left<temp){
      //printf("3\n");
      res=dfs(index-1, left-1, Lv_n, Lv_p);
    }
    else if(left>=temp){
      //printf("4\n");
      res=Lv_p[index-1]+1+dfs(index-1, left-2-Lv_n[index-1], Lv_n, Lv_p);
    }
  }

  return res;
} ./Main.c: In function ‘main’:
./Main.c:26:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^