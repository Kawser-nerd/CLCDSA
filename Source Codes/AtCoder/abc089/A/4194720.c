#include "stdio.h"

int main()
{
  float N;
  scanf("%4f%*[^\n]", &N);
  getchar();
  printf("%g", floor(N / 3));
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:16: warning: implicit declaration of function ‘floor’ [-Wimplicit-function-declaration]
   printf("%g", floor(N / 3));
                ^
./Main.c:8:16: warning: incompatible implicit declaration of built-in function ‘floor’
./Main.c:8:16: note: include ‘<math.h>’ or provide a declaration of ‘floor’
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%4f%*[^\n]", &N);
   ^