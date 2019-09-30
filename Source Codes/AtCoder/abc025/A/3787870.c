#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  char S[5];
  int N, k, r;

  scanf("%s", S);
  scanf("%d", &N);

  if(N % 5 == 0){
    k = N / 5;
    printf("%c%c\n", S[k - 1], S[4]);
  }else{
    k = N / 5;
    r = N % 5;
    printf("%c%c\n", S[k], S[r - 1]);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:11:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%s", S);
   ^
./Main.c:11:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:11:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:16:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("%c%c\n", S[k - 1], S[4]);
     ^
./Main.c:16:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:16:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:20:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("%c%c\n", S[k], S[r - 1]);
     ^
./Main.c:20:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’