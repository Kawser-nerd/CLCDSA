#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a,const void *b){
  if(*(int*)a-*(int*)b > 0) return 1;
  return -1;
}

long long gcd(long long x,long long y){
    if(y == 0) return x;
    return gcd(y,x%y);
}

int main(void){
  int N;
  scanf("%d",&N);

  N++;
  int x[N];
  for(int i = 0;i < N;i++) scanf("%d",&x[i]);

  qsort(x,N,sizeof(int),compare_int);

  int ans = x[1]-x[0];
  for(int i = 0;i < N-1;i++){
    ans = gcd(ans,x[i+1]-x[i]);
  }

  printf("%d\n",ans);

  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^
./Main.c:20:28: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   for(int i = 0;i < N;i++) scanf("%d",&x[i]);
                            ^