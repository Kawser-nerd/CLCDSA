#include <stdio.h>
#include <stdlib.h>//random,NULL
#include <string.h>
#include <time.h>
#include <unistd.h>//sleep()
#include <math.h>

#define true 1
#define false 0

#define rep(i,n) for(int i=0; i<((int)n); i++)
#define REP(i,n) for(int i=0; i<=((int)n); i++)
#define srep(i,a,n) for(int i=a; i<((int)n); i++)
#define SREP(i,a,n) for(int i=a; i<=((int)n); i++)
#define rrep(i,n) for(int i=n-1; i>=0; i--)
#define RREP(i,n) for(int i=n; i>=0; i--)
#define INF 10000000000000

//?????
//c?????????????N^3??????????
//bellman_ford??????
//????????????????
/*
  ????????
  N-1??????????N????????????????
  ?????N-1????????????????
  ??N???????????????????????????inf?????????
  ??N???????????N?????????????????inf
*/

//????????????bellman_ford??????

long bellman_ford(int N, int M, int **edge){
  long *d=(long *)malloc(sizeof(long)*N);
  rep(i,N){
    d[i]=INF;
  }
  d[0]=0;

  rep(k,N-1){
    //int update=false;
    rep(j,M){
      if(d[edge[j][0]]!=INF && d[edge[j][0]]+edge[j][2]<d[edge[j][1]]){
        d[edge[j][1]]=d[edge[j][0]]+edge[j][2];
        //update=true;
      }
    }
  }
  // rep(i,N){
  //   printf("d[%d] = %d, ", i, d[i]);
  // }
  // printf("\n");
  //??????d[N-1]??N-1???????????????
  long record=d[N-1];

  rep(k,N){
    rep(j,M){
      if(d[edge[j][0]]+edge[j][2]<d[edge[j][1]]){
        d[edge[j][1]]=d[edge[j][0]]+edge[j][2];
      }
    }
  }
  // rep(i,N){
  //   printf("d[%d] = %d, ", i, d[i]);
  // }
  // printf("\n");

  if(record>d[N-1]){
    return INF*(-1);
  }
  else{
    return record;
  }
}




int main(){
  char buf[1024];
  int N,M;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %d", &N, &M);

  int *array=(int *)malloc(sizeof(int)*N);
  rep(i,N){
    ;
  }

  int **edge=(int **)malloc(sizeof(int *)*M);
  rep(i,M){
    edge[i]=(int *)malloc(sizeof(int)*3);
  }
  rep(i,M){
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf, "%d %d %d", &edge[i][0], &edge[i][1], &edge[i][2]);
    edge[i][0]--;
    edge[i][1]--;
  }
  rep(i,M){
    edge[i][2]=edge[i][2]*(-1);
  }

  long longest=bellman_ford(N, M, edge)*(-1);

  if(longest==INF){
    printf("inf\n");
  }
  else{
    printf("%ld\n", longest);
  }

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:83:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:96:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf,sizeof(buf),stdin);
     ^