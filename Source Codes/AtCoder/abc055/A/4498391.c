#include <stdio.h>
#include <string.h>
int main(){
  int n;

  scanf("%d", &n);

  printf("%d", 800*n - 200*(n/15));

  printf("\n");
  
} ./Main.c: In function �main�:
./Main.c:6:3: warning: ignoring return value of �scanf�, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^