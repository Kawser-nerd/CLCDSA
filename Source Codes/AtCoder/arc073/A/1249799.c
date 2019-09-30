#include<stdio.h>

int main() {
  int N,T;
  scanf("%d%d",&N,&T);
  int A[N];
  int a;
  for (int i=0;i<N;i++) {
      scanf("%d",&a);
      A[i]=a;
  }
  int ans = 0;
  for (int i=0;i<N-1;i++) {
    int p = A[i+1] - A[i];
    if (p <= T) ans += p;
    else ans += T;
  }
  printf("%d\n",ans+T);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d",&N,&T);
   ^
./Main.c:9:7: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
       scanf("%d",&a);
       ^