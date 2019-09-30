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

//???????????
int count=0;

//??????????n!????????
//???(n,n)???(i,j)???????????????????

//?????????
void jyun(int *t, int n, int N, int **linking);
//???????????????????????true or false
int judge(int *t, int N, int **linking);


void jyun(int *t, int n, int N, int **linking){
  if(n<2){
    //????????
    count=count+judge(t, N, linking);
    // if(judge(t, N, linking)==true){
    //   printf("t[N] = ");
    //   rep(i,N){
    //     printf("%d ",t[i]);
    //   }
    //   printf("\n");
    // }
    return ;
  }

  int k,temp;
  k=n-1;
  rrep(i,n){
    temp=t[k];
    t[k]=t[i];
    t[i]=temp;
    jyun(t, k, N, linking);
    t[i]=t[k];
    t[k]=temp;
  }
}


int judge(int *t, int N, int **linking){
  int flag=1;
  if(t[0]!=0){
    flag=0;
  }
  rep(i,N-1){
    if(linking[t[i]][t[i+1]]==false){
      flag=0;
    }
  }

  return flag;
}


int main(){
  char buf[1024];
  int N,M;

  fgets(buf, sizeof(buf), stdin);
  sscanf(buf, "%d %d", &N, &M);

  int *t=(int *)malloc(sizeof(int)*N);
  rep(i,N){
    t[i]=i;
  }
  //???? 0~N-1

  int **Sides=(int **)malloc(sizeof(int *)*M);
  rep(i,M){
    Sides[i]=(int *)malloc(sizeof(int)*2);
  }

  rep(i,M){
    fgets(buf, sizeof(buf), stdin);
    sscanf(buf, "%d %d", &Sides[i][0], &Sides[i][1]);
  }

  //????0~N??????????
  rep(i,M){
    Sides[i][0]--;
    Sides[i][1]--;
  }


  //???i????j????????????????true or false
  //linking? (N,N) ??
  int **linking=(int **)malloc(sizeof(int *)*N);
  rep(i,N){
    linking[i]=(int *)malloc(sizeof(int)*N);
  }
  rep(i,N){
    rep(j,N){
      if(i==j){
        linking[i][j]=true;
      }
      else{
        linking[i][j]=false;
      }
    }
  }

  rep(i,N){
    rep(j,M){
      if(Sides[j][0]==i){
        linking[i][Sides[j][1]]=true;
      }
      else if(Sides[j][1]==i){
        linking[i][Sides[j][0]]=true;
      }
    }
  }

  // rep(i,N){
  //   rep(j,N){
  //     printf("%d ", linking[i][j]);
  //   }
  //   printf("\n");
  // }


  jyun(t, N, N, linking);

  printf("%d\n",count);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:76:3: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
   fgets(buf, sizeof(buf), stdin);
   ^
./Main.c:91:5: warning: ignoring return value of ‘fgets’, declared with attribute warn_unused_result [-Wunused-result]
     fgets(buf, sizeof(buf), stdin);
     ^