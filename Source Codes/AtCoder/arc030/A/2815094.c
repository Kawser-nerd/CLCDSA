#include <stdio.h>

int main(){
  int n,k;

  scanf("%d%d", &n, &k);

  if((n/2) >= k){
    printf("YES\n");
  } else {
    printf("NO\n");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d", &n, &k);
   ^