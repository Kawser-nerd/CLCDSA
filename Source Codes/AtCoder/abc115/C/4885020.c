#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a,const void *b){
  if(*(int*)a-*(int*)b > 0) return 1;
  return -1;
}

int min(int a,int b){
  if(a < b){
    return a;
  }
  return b;
}

int main(void){
  int N,K;
  scanf("%d%d",&N,&K);

  int h[N];
  for(int i = 0;i < N;i++) scanf("%d",&h[i]);

  qsort(h,N,sizeof(int),compare_int);

  int ans = 1e9;
  for(int i = 0;i < N-K+1;i++){
    ans = min(ans,h[i+K-1]-h[i]);
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:18:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&K);
   ^
./Main.c:21:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d",&h[i]);
                            ^