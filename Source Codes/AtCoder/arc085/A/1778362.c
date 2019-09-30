#include<stdio.h>
#include<math.h>

int main(void){
  int n, m;
  int ans;
  scanf("%d %d", &n, &m);
  ans = (1900 * m + 100 * (n-m)) / (1 /pow(2,m));
  printf("%d\n", ans);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &m);
   ^