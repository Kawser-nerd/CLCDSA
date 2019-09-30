#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
 
int main(void){
  
  int N;

  scanf("%d", &N);

  if(N <= 59){
    printf("Bad\n");
  }else if(N <= 89){
    printf("Good\n");
  }else if(N <= 99){
    printf("Great\n");
  }else{
    printf("Perfect\n");
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%d", &N);
   ^
./Main.c:10:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:10:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:13:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("Bad\n");
     ^
./Main.c:13:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:13:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:15:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("Good\n");
     ^
./Main.c:15:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:17:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("Great\n");
     ^
./Main.c:17:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:19:5:...