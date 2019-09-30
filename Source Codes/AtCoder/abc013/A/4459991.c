#include <stdio.h>
int main(void){
char s[5];
  scanf("%s",&s);
  if(s[0]=='A'){printf("1\n");}
    if(s[0]=='B'){printf("2\n");}
    if(s[0]=='C'){printf("3\n");}
    if(s[0]=='D'){printf("4\n");}
    if(s[0]=='E'){printf("5\n");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[5]’ [-Wformat=]
   scanf("%s",&s);
         ^
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&s);
   ^