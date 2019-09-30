#include<stdio.h>

int main(){
  long X;
  scanf("%ld", &X);
  X = (int)sqrt(X);
  X = (int)sqrt(X);
  printf("%d\n", X);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:12: warning: implicit declaration of function ‘sqrt’ [-Wimplicit-function-declaration]
   X = (int)sqrt(X);
            ^
./Main.c:6:12: warning: incompatible implicit declaration of built-in function ‘sqrt’
./Main.c:6:12: note: include ‘<math.h>’ or provide a declaration of ‘sqrt’
./Main.c:8:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
   printf("%d\n", X);
          ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%ld", &X);
   ^