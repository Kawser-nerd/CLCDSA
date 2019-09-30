#include<stdio.h>
#include<string.h>
int main(){
  char s[100];
  scanf("%s",s);
  printf("%c%d%c",s[0],strlen(s)-2,s[strlen(s)-1]);
} ./Main.c: In function ‘main’:
./Main.c:6:10: warning: format ‘%d’ expects argument of type ‘int’, but argument 3 has type ‘size_t {aka long unsigned int}’ [-Wformat=]
   printf("%c%d%c",s[0],strlen(s)-2,s[strlen(s)-1]);
          ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^