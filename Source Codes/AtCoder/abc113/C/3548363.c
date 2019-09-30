#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef struct {
  int num;
  int P;
  long long int Y;
  int y;
} bigint;

int cmp( const void *p, const void *q ) {
  return ((bigint*)p)->Y - ((bigint*)q)->Y;
}

int cmp2( const void *p, const void *q ) {
    return ((bigint*)p)->num - ((bigint*)q)->num;
}

void sixint(int N){
  int i;
  int k[6];
  for(i=5;i>=0;i--){
    k[i]=N%10;
    N=(int)N/10;
  }
  for(i=0;i<6;i++){
    printf("%d",k[i]);
  }
}

int main(){
  int N,M,i;
  scanf("%d%d",&N,&M);
  bigint X[M];
  int c_P[N+1];

  for(i=0;i<M;i++){
    scanf("%d%lld",&X[i].P,&X[i].Y);
    X[i].num=i;
  }
  
  qsort(X, M, sizeof(bigint), cmp);

  for(i=0;i<N+1;i++){
    c_P[i]=1;
  }

  for(i=0;i<M;i++){
    X[i].y = c_P[X[i].P];
    c_P[X[i].P]=c_P[X[i].P]+1;
  }
  
  qsort(X, M, sizeof(bigint), cmp2 );

  for(i=0;i<M;i++){
    sixint(X[i].P);
    sixint(X[i].y);
    printf("\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:34:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:39:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%lld",&X[i].P,&X[i].Y);
     ^