#include <stdio.h>
#include <stdlib.h>

typedef struct pair{
  int x,y;
}point;

int compare_int(const void *a,const void *b){
  return (*(point*)a).x > (*(point*)b).x;
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  point A[N];
  for(int i = 0;i < N;i++) scanf("%d%d",&A[i].x,&A[i].y);

  qsort(A,N,sizeof(point),compare_int);

  int cnt = 0;
  long long money = 0;  
  for(int i = 0;;i++){
    if(cnt+A[i].y < M){
      cnt += A[i].y;
      money += (long long)A[i].y*A[i].x;
    }else{
      money += (long long )(M-cnt)*A[i].x;
      break;
    }
  }

  printf("%lld\n",money);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:17:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d%d",&A[i].x,&A[i].y);
                            ^