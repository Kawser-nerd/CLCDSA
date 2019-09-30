#include<stdio.h>
int main (){
  char s[51];
  scanf("%s", s);
  if(s[strlen(s)-1] == 'T'){
    printf("YES\n");
  }else{
    printf("NO\n");
  }
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:8: warning: implicit declaration of function ‘strlen’ [-Wimplicit-function-declaration]
   if(s[strlen(s)-1] == 'T'){
        ^
./Main.c:5:8: warning: incompatible implicit declaration of built-in function ‘strlen’
./Main.c:5:8: note: include ‘<string.h>’ or provide a declaration of ‘strlen’
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s", s);
   ^