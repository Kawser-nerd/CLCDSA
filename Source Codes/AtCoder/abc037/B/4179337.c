#include<stdio.h>

int main(){
  long N, Q, L, R, T, a[100] = {0}, i, j;
  
  scanf("%ld %ld", &N, &Q);
  for (i = 0; i < Q; i++){
    scanf("%ld %ld %ld", &L, &R, &T);
    for(j = L - 1; j < R; j++){
      a[j] = T;
    }
  }
  
  for (i = 0; i < N; i++){
    printf("%ld\n", a[i]);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld %ld", &N, &Q);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%ld %ld %ld", &L, &R, &T);
     ^