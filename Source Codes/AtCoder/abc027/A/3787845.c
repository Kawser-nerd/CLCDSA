#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  int l1, l2, l3;

  scanf("%d%d%d", &l1, &l2, &l3);

  if(l1 == l2){
    printf("%d\n", l3);
  }else if(l2 == l3){
    printf("%d\n", l1);
  }else{
    printf("%d\n", l2);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d%d%d", &l1, &l2, &l3);
   ^
./Main.c:10:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:10:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:13:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%d\n", l3);
     ^
./Main.c:13:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:13:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:15:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("%d\n", l1);
     ^
./Main.c:15:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:17:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("%d\n", l2);
     ^
./Main.c:17:5: note: include ‘<stdio.h>’ or provide a declaration of ‘p...