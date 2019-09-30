#include <stdio.h>
#include <math.h>

int main(void){
  int n, i, j;
  scanf("%d", &n);
  int max = 1;
  
  for(i = 2; i < n / 2; i++){
    for(j = 1; (int)pow(i, j) <= n; j++){
      if(max < (int)pow(i, j)) max = (int)pow(i, j);
    }
  }
  
  printf("%d\n", max);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &n);
   ^