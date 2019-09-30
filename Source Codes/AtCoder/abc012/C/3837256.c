#include<stdio.h>
int N, i;
int main(){
  scanf("%d", &N);
  N=2025-N;
  for(i=1; i<10; i++){
    if(N%i==0 && N/i<10){
      printf("%d x %d\n", i, N/i);
    }
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^