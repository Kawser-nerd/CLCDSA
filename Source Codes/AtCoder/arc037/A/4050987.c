#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N, i;
  int ans = 0;

  scanf("%d", &N);

  int m[N];

  for(i = 0; i < N; i++){
    scanf("%d", &m[i]);
    if(m[i] < 80){
      ans += 80 - m[i];
    }
  }

  printf("%d\n", ans);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &m[i]);
     ^