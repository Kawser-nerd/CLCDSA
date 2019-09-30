#include<stdio.h>

int main(){
  int A, B, C, r, i;
  
  scanf("%d %d %d", &A, &B, &C);
  
  for (i = 1; i < B; i++){
    if(A*i%B == C){
      break;
    }
  }
  if(i == B){
    printf("NO\n");
  } else {
    printf("YES\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %d %d", &A, &B, &C);
   ^