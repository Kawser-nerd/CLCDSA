#include<stdio.h>

int main(){
  int x, i, a[6], xi;
  long N;
  
  scanf("%ld", &N);
  N = N % 30;
  for (i = 0; i < 6; i++){
    a[i] = i + 1;
  }
  
  for (i = 0; i < N; i++){
    xi = i%5;
    x = a[xi];
    a[xi] = a[xi + 1];
    a[xi + 1] = x;
  }
  
  for (i = 0; i < 6; i++){
    printf("%d", a[i]);
  }
  printf("\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &N);
   ^