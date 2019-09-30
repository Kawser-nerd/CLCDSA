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
#define INF 1000000000

int min(int a, int b){
  if(a>=b){
    return b;
  }
  else{
    return a;
  }
}

int max(int a, int b){
  if(a>=b){
    return a;
  }
  else{
    return b;
  }
}

//????????????????????????
//warshall_flyod??~O(N^3)???????~O(N^2)?
//???????????????????????????????
//??????????????????(~O(N^2))

void warshall_floyd(int N, int **d){
  rep(k,N){
    rep(i,N){
      rep(j,N){
        d[i][j]=min(d[i][j], d[i][k]+d[k][j]);
      }
    }
  }
}


int main(){
  char buf[1024];
  int N,M;

  fgets(buf,sizeof(buf),stdin);
  sscanf(buf, "%d %d", &N, &M);

  int **Sides=(int **)malloc(sizeof(int *)*M);
  rep(i,M){
    Sides[i]=(int *)malloc(sizeof(int)*3);
  }
  rep(i,M){
    fgets(buf,sizeof(buf),stdin);
    sscanf(buf, "%d %d %d", &Sides[i][0], &Sides[i][1], &Sides[i][2]);
    Sides[i][0]--;
    Sides[i][1]--;
  }

  int **d=(int **)malloc(sizeof(int *)*N);
  rep(i,N){
    d[i]=(int *)malloc(sizeof(int)*N);
  }
  rep(i,N){
    rep(j,N){
      if(i==j){
        d[i][j]=0;
      }
      else{
        d[i][j]=INF;
      }
    }
  }
  rep(i,M){
    //???????????????????
    //????????????????????
    d[Sides[i][0]][Sides[i][1]]=Sides[i][2];
    d[Sides[i][1]][Sides[i][0]]=Sides[i][2];
  }
  // rep(i,N){
  //   rep(j,N){
  //     printf("d[%d][%d] = %d, ", i, j, d[i][j]);
  //   }
  //   printf("\n");
  // }

  warshall_floyd(N, d);

  // rep(i,N){
  //   rep(j,N){
  //     printf("d[%d][%d] = %d, ", i, j, d[i][j]);
  //   }
  //   printf("\n");
  // }

  int best=INF;
  rep(i,N){
    int worst=0;
    rep(j,N){
      //printf("d[i][j] = %d\n", d[i][j]);
      worst=max(worst, d[i][j]);
      //printf("worst = %d\n", worst);
    }
    //printf("worst[i] = %d\n", worst);
    best=min(best, worst);
    //printf("best = %d\n", best);
  }

  printf("%d\n", best);

  return 0;

} ./Main.c: In function ‘main’:
./Main.c:57:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf,sizeof(buf),stdin);
   ^
./Main.c:65:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf,sizeof(buf),stdin);
     ^