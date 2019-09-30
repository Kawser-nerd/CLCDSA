#include <math.h>

int main(void){
  
  char S[128];
  long long K;
  long long i, len = 0;
  long long one = 0;

  scanf("%s", S);

  while(S[len]){
    len++;
  }

  for(i = 0; i < len; i++){
    if(S[i] == '1'){
      one++;
    }else{
      break;
    }
  }
  
  scanf("%lld", &K);

  if(K <= one){
    printf("1\n");
  }else{
    printf("%c\n", S[one]);
  }
  
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:10:3: warning: implicit declaration of function ‘scanf’ [-Wimplicit-function-declaration]
   scanf("%s", S);
   ^
./Main.c:10:3: warning: incompatible implicit declaration of built-in function ‘scanf’
./Main.c:10:3: note: include ‘<stdio.h>’ or provide a declaration of ‘scanf’
./Main.c:27:5: warning: implicit declaration of function ‘printf’ [-Wimplicit-function-declaration]
     printf("1\n");
     ^
./Main.c:27:5: warning: incompatible implicit declaration of built-in function ‘printf’
./Main.c:27:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’
./Main.c:29:5: warning: incompatible implicit declaration of built-in function ‘printf’
     printf("%c\n", S[one]);
     ^
./Main.c:29:5: note: include ‘<stdio.h>’ or provide a declaration of ‘printf’