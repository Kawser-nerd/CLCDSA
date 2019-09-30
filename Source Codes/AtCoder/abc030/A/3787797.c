#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  int A, B, C, D;

  scanf("%d%d%d%d", &A, &B, &C, &D);

  if((B * C) < (A * D)){
    printf("AOKI\n");
  }else if((B * C) > (A * D)){
    printf("TAKAHASHI\n");
  }else{
    printf("DRAW\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d%d", &A, &B, &C, &D);
   ^
./Main.c:10:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:10:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:13:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("AOKI\n");
     ^
./Main.c:13:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:13:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:15:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("TAKAHASHI\n");
     ^
./Main.c:15:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:17:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("DRAW\n");
     ^
./Main.c:17:5: note: include ‘<stdio.h>’ or provide a declaration of ...