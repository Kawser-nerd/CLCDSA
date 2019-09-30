#include <stdio.h>

int main(void){
  int A, B, K, cnt=0;
  int i;
  scanf("%d %d %d", &A, &B, &K);
  for(i=100;i>0;i--){
    if(A%i==0 && B%i==0) cnt++;
    if(cnt==K) break;
  }
  printf("%d\n",i);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &A, &B, &K);
   ^