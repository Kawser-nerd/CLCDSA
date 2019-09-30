#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(void){

  int N;
  int i;
  int sum = 0;
  int ave;
  int c1 = 0, c2 = 0;

  scanf("%d", &N);

  int a[N];

  for(i = 0; i < N; i++){
    scanf("%d", &a[i]);
  }

  for(i = 0; i < N; i++){
    sum += a[i];
  }

  ave = sum / N;

  for(i = 0; i < N; i++){
    c1 += (ave - a[i]) * (ave - a[i]);
    c2 += (ave + 1 - a[i]) * (ave + 1 - a[i]);
  }

  if(c1 < c2){
    printf("%d\n", c1);
  }else{
    printf("%d\n", c2);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:14:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:19:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^