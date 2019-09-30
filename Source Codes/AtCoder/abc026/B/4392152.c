#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a,const void *b){
  return *(long*)a-*(long*)b;
}

int main(void){
  int N,cnt;
  double ans = 0;
  scanf("%d",&N);

  int r[N];
  for(int i = 0;i < N;i++) scanf("%d",&r[i]);
  qsort(r,N,sizeof(int),compare_int);
  
  for(int i = N-1;i >= 0;i--){
    ans += r[i]*r[i]*((cnt++)%2 == 0 ? 1:-1);
  }
  printf("%.10lf\n",ans*3.1415926535);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:14:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d",&r[i]);
                            ^