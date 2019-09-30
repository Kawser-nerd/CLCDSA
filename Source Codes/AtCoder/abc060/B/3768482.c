#include <stdio.h>

int main(){
  int A, B, C;

  scanf("%d%d%d", &A, &B, &C);

  for(int i = 1; i <= B; i++){
    if((A*i)%B == C){
      printf("YES\n");
      return 0;
    }
  }

  printf("NO\n");
  
  return 0;
}

/*
???? A, B, C ????
  A*i = C (mod B)
??????? i (1 <= i <= B) ???????
*/ ./Main.c: In function ‘main’:
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d%d%d", &A, &B, &C);
   ^