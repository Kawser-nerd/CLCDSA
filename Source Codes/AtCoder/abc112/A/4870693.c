#include <stdio.h>

int
main(int argc, char *argv[])
{
  int N;
  scanf("%d", &N);
  
  if(N == 1){
    printf("%s\n", "Hello World");
  }
  else{
    int A, B;
    scanf("%d%d", &A, &B);
    printf("%d\n", A+B);
  }
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:14:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &A, &B);
     ^