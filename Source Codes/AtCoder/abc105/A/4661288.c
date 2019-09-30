#include <stdio.h>
int main() {
  int N,K;
  scanf("%d %d",&N,&K);
  if (N % K == 0) {
    printf("0\n");
  } else {
    printf("1\n");
  }
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d",&N,&K);
   ^