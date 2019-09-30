#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N, i;
  int min = 50, max = 0, sum = 0;

  scanf("%d", &N);

  int t[N];

  for(i = 0; i < N; i++){
    scanf("%d", &t[i]);
  }

  if(N == 1){
    printf("%d\n", t[0]);
  }else if(N == 2){
    if(t[0] > t[1]){
      printf("%d\n", t[0]);
    }else{
      printf("%d\n", t[1]);
    }
  }else if(N == 3){
    for(i = 0; i < N; i++){
      if(max < t[i]){
	max = t[i];
      }
      sum += t[i];
    }
    if(max > (sum - max)){
      printf("%d\n", max);
    }else{
      printf("%d\n", sum - max);
    }
  }else{
    for(i = 0; i < N; i++){
      if(min > t[i]){
	min = t[i];
      }
      if(max < t[i]){
	max = t[i];
      }
      sum += t[i];
    }
    if(max > (sum - max)){
      printf("%d\n", max);
    }else if((sum - max - min) < max){
      printf("%d\n", sum - max);
    }else if((max + min) > (sum - max - min)){
      printf("%d\n", max + min);
    }else{
      printf("%d\n", sum - max - min);
    }
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:12:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &t[i]);
     ^