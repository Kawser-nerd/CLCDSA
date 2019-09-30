#include <stdio.h>

int main() {
  int N;
  scanf("%d",&N);
  int a=N/100;
  int solve=100*a+10*a+a;
  if ((solve) >= N) printf("%d\n",solve);
  else printf("%d\n",solve+111);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d",&N);
   ^