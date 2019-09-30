#include <stdio.h>
#include <stdlib.h>

int compare_int(const void *a, const void *b) {
    return *(int*)a - *(int*)b;
}

int common_factor(int a, int b) {
  int r = a%b;
  while (r != 0) {
    a = b;
    b = r;
    r = a%b;
  }
  return b;
}

int main() {
  int N,X;
  scanf("%d %d",&N,&X);
  int x[N+1];
  for (int i = 0; i < N; i++) {
    scanf("%d",&x[i]);
  }
  x[N] = X;
  qsort(x,N+1,sizeof(int),compare_int);
  int dif_x[N];
  for (int i = 0; i < N; i++) {
    dif_x[i] = x[i+1] - x[i];
  }
  if (N == 1) {
    printf("%d\n",dif_x[0]);
    return 0;
  }
  qsort(dif_x,N,sizeof(int),compare_int);
  int ans = common_factor(dif_x[0],dif_x[1]);
  if (N >= 3) {
    for (int i = 2; i < N; i++) {
      ans = common_factor(ans,dif_x[i]);
    }
  }
  printf("%d\n",ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:20:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&X);
   ^
./Main.c:23:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&x[i]);
     ^