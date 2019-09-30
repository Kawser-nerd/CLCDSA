#include <stdio.h>

int main(void){
  int n, m;
  scanf("%d", &n);
  m = n % 10;
  n /= 10;
  if(n == 9 || m == 9) printf("Yes\n");
  else printf("No\n");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^