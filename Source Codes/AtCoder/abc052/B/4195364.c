#include<stdio.h>

int main(){
  int N, len, max;
  char S[101];
  
  scanf("%d", &N);
  scanf("%s", &S);
  
  max = 0; N = 0;
  while(S[len]){
    if(S[len] == 'I'){
      N++;
    } else {
      N--;
    }
    if(max < N){
      max = N;
    }
    len++;
  }
  
  printf("%d\n", max);
} ./Main.c: In function ‘main’:
./Main.c:8:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[101]’ [-Wformat=]
   scanf("%s", &S);
         ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d", &N);
   ^
./Main.c:8:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", &S);
   ^