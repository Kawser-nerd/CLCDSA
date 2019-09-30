#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a,const void *b){
  return *(long*)a-*(long*)b;
}

int main(void){
  int N,M;
  scanf("%d%d",&N,&M);

  int X[M];
  for(int i = 0;i < M;i++) scanf("%d",&X[i]);

  qsort(X,M,sizeof(int),compare_int);

  M--;
  int gap[M];
  for(int i = 0;i < M;i++){
    gap[i] = X[i+1]-X[i];
  }

  qsort(gap,M,sizeof(int),compare_int);

  long long ans = X[M]-X[0];
  for(int i = M-1;i > M-N && i >= 0;i--){
    ans -= gap[i];
  }

  printf("%lld\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&M);
   ^
./Main.c:13:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < M;i++) scanf("%d",&X[i]);
                            ^