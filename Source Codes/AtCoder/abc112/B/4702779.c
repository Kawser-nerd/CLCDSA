#include <stdio.h>

int main() {
  int n,T;
  scanf("%d %d",&n,&T);
  int min=1001;
  for (int i = 0; i < n; i++) {
    int c,t;
    scanf("%d %d",&c,&t);
    if (t <= T && min > c) min = c;
  }
  if (min > 1000) {
    printf("TLE\n");
    return 0;
  }
  printf("%d\n",min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&n,&T);
   ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d",&c,&t);
     ^