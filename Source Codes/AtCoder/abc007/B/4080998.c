#include <stdio.h>

int main(){
  char A[11];
  scanf("%s", A);
  if(A[0] == 'a' && A[1] == '\0'){
    printf("-1");
  }
  else{
    printf("a");
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", A);
   ^