#include <stdio.h>
#include <string.h>
int main(){
  int n, m;

  scanf("%d%d", &n, &m);

  printf("%d", (n-1) * (m-1));
  printf("\n");
  
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &m);
   ^