#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N;
  int num[8], i;

  for(i = 1; i <= 4; i++){
    num[i] = 0;
  }

  scanf("%d", &N);

  char c[N];
  int min = N, max = 0;

  scanf("%s", c);

  for(i = 0; i < N; i++){
    if(c[i] == '1'){
      num[1]++;
    }else if(c[i] == '2'){
      num[2]++;
    }else if(c[i] == '3'){
      num[3]++;
    }else{
      num[4]++;
    }
  }

  for(i = 1; i <= 4; i++){
    if(num[i] < min){
      min = num[i];
    }
    if(num[i] > max){
      max = num[i];
    }
  }

  printf("%d %d\n", max, min);
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:16:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:21:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", c);
   ^