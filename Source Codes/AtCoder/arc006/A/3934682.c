#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int E[6], B, L[6], i, j;
  int s = 0, b = 0;

  for(i = 0; i < 6; i++){
    scanf("%d", &E[i]);
  }
  scanf("%d", &B);
  for(i = 0; i < 6; i++){
    scanf("%d", &L[i]);
  }

  for(i = 0; i < 6; i++){
    for(j = 0; j < 6; j++){
      if(E[j] == L[i]){
	s++;
      }
    }
    if(L[i] == B){
      b++;
    }
  }

  if(s == 6){
    printf("1\n");
  }else if(s == 5 && b == 1){
    printf("2\n");
  }else if(s == 5){
    printf("3\n");
  }else if(s == 4){
    printf("4\n");
  }else if(s == 3){
    printf("5\n");
  }else{
    printf("0\n");
  }
   
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &E[i]);
     ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &B);
   ^
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &L[i]);
     ^