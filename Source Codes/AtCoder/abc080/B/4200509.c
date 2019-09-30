#include<stdio.h>

int main(){
  int N, f, d;
  scanf("%d", &N);
  d = N;
  
  do{
    f += N%10;
    N /= 10;
  }while(N != 0);
  
  if(d%f == 0){
    printf("Yes\n");
  } else {
    printf("No\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^