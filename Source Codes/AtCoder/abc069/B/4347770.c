#include<stdio.h>
#include<string.h>
int main(){
  char S[200];
  scanf("%s",S);
  printf("%c%d%c\n",S[0],strlen(S)-2,S[strlen(S)-1]);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘size_t {aka long unsigned int}’ [-Wformat=]
   printf("%c%d%c\n",S[0],strlen(S)-2,S[strlen(S)-1]);
          ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",S);
   ^