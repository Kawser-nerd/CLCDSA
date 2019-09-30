#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  char W[16];

  scanf("%s", W);

  printf("%ss\n", W);
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%s", W);
   ^
./Main.c:10:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:10:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:12:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("%ss\n", W);
   ^
./Main.c:12:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:12:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’