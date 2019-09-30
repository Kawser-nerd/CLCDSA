#include<stdio.h>

int main(){
  int N, M, a[50] = {0}, i, p, q;
  scanf("%d %d", &N, &M);
  for (i = 0; i < M; i++){
    scanf("%d %d", &p, &q);
    a[p - 1]++;
    a[q - 1]++;
  }
  for (i = 0; i < N; i++){
    printf("%d\n", a[i]);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d", &N, &M);
   ^
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d %d", &p, &q);
     ^