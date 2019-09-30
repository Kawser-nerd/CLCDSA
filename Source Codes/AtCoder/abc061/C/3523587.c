#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  int n, i, a, b;
  long long k, data[100001] = {0}, c = 0;

  scanf("%d%lld", &n, &k);

  for(i = 0; i < n; i++){
    scanf("%d%d", &a, &b);
    data[a] += b;
  }
  
  for(i = 0; c < k; i++){
    c += data[i];
  }
  
  printf("%d\n", i - 1);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%lld", &n, &k);
   ^
./Main.c:15:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^