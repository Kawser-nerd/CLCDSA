#include<stdio.h>
#include<string.h>
int main(){
  char s[222222];
  scanf("%s",s);
  printf("%d",strrchr(s,'Z')-strchr(s,'A')+1);
} ./Main.c: In function ‘main’:
./Main.c:6:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 2 has type ‘long int’ [-Wformat=]
   printf("%d",strrchr(s,'Z')-strchr(s,'A')+1);
          ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^