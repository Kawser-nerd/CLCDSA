#include <stdlib.h>
#include <stdbool.h>
 
int main(void){

  long X;
  long sum = 0;
  long i = 0;

  scanf("%ld", &X);

  while(sum < X){
    i++;
    sum += i;
  }

  printf("%ld\n", i);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%ld", &X);
   ^
./Main.c:10:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:10:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:17:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%ld\n", i);
   ^
./Main.c:17:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:17:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’