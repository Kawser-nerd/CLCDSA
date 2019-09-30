#include<stdio.h>
int A, B, C, i;
int main(){
  scanf("%d%d%d", &A, &B, &C);
  for(i=0; i<B; i++){
    if((A*i)%B == C){
      printf("YES\n");
      return 0;
    }
  }
  printf("NO\n");
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &A, &B, &C);
   ^