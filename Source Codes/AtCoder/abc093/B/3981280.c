#include <stdio.h>

int main(void){
  int a, b, k;
  scanf("%d%d%d", &a, &b, &k);
  int i;
  for(i = a; i <= b; i++){
    if(i < a + k || b - k < i){
      printf("%d\n", i);
    }
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &a, &b, &k);
   ^