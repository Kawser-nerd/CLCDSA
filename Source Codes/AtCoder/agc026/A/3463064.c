#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
 
int main(void){

  int N;
  int i;
  int j = 1;
  int n = 0;

  scanf("%d", &N);

  int a[N];

  for(i = 0; i < N; i++){
    scanf("%d", &a[i]);
  }

  while(j < N){
    if(a[j] == a[j - 1]){
      n++;
      j += 2;
    }else{
      j++;
    }
  }

  printf("%d\n", n);
    
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:13:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:18:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a[i]);
     ^