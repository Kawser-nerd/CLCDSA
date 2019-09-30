#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N, n, i;

  scanf("%d", &N);

  char S[N];
  
  scanf("%s", S);

  char T[N];

  n = N / 2;

  if(n % 3 == 0){
    for(i = 0; i < N; i++){
      if(i % 3 == 0){
	T[i] = 'b';
      }else if(i % 3 == 1){
	T[i] = 'c';
      }else{
	T[i] = 'a';
      }
    }
  }else if(n % 3 == 1){
    for(i = 0; i < N; i++){
      if(i % 3 == 0){
	T[i] = 'a';
      }else if(i % 3 == 1){
	T[i] = 'b';
      }else{
	T[i] = 'c';
      }
    }
  }else{
    for(i = 0; i < N; i++){
      if(i % 3 == 0){
	T[i] = 'c';
      }else if(i % 3 == 1){
	T[i] = 'a';
      }else{
	T[i] = 'b';
      }
    }
  }

  int t = 0;

  for(i = 0; i < N; i++){
    if(S[i] != T[i]){
      t++;
      break;
    }
  }

  if((t != 0) || (N % 2 == 0)){
    printf("-1\n");
  }else{
    printf("%d\n", n);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:15:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", S);
   ^