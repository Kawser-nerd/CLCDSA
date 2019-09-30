#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a,const void *b){
  return *(long*)a-*(long*)b;
}

int main(void){
  int N,K;
  int ans = 0;
  scanf("%d%d",&N,&K);
  int l[N];

  for(int i = 0;i < N;i++) scanf("%d",&l[i]);
  qsort(l,N,sizeof(int),compare_int);

  for(int i = N-1;i >= N-K;i--){
    ans += l[i];
  }

  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&K);
   ^
./Main.c:14:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d",&l[i]);
                            ^