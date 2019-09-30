#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b)
{
    return *(int*)b - *(int*)a;
}

int main(){
  int i,N,K,R[101];
  double ans=0;
  scanf("%d %d",&N,&K);
  for(i=0;i<N;i++){
    scanf("%d",&R[i]);
  }
  qsort(R, N, sizeof(int), compare_int);
  for(i=K-1;i>=0;i--){
    ans=(ans+(double)R[i])/2.0;
  }
  printf("%f\n",ans);
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&K);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&R[i]);
     ^