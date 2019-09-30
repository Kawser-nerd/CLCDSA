#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){

  int N, i;

  scanf("%d", &N);

  printf("1");
  for(i = 1; i <= N - 1; i++){
    printf("0");
  }
  printf("7\n");
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d", &N);
   ^
./Main.c:10:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:10:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:12:3: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
   printf("1");
   ^
./Main.c:12:3: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:12:3: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’