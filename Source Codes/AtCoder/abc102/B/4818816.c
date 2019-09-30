#include <stdio.h>

int main()
{
  int n, min = 1e9, max = 1, i, a;
  scanf("%d", &n);
  for(i = 0; i < n; ++i) {
    scanf("%d",&a);
    if(a < min) { min = a;}
    if(max < a) { max = a;}
  }
  printf("%d", max - min);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d",&a);
     ^