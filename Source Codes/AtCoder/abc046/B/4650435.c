#include <stdio.h>

int main(){
  int n,k;
  scanf("%d %d", &n, &k);
  int answer = k;
  for(int i = 1; i < n; ++i) answer *= (k - 1);
  printf("%d\n", answer);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &n, &k);
   ^