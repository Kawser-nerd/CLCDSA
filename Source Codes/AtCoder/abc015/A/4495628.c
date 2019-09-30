#include <stdio.h>
#include <string.h>
char aa[100],bb[100];
int a,b;
int main(void){
  scanf("%s",&aa);
scanf("%s",&bb);
  a=strlen(aa);
  b=strlen(bb);
  if(a>b){printf("%s",aa);}
  else{printf("%s",bb);}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
   scanf("%s",&aa);
         ^
./Main.c:7:7: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
 scanf("%s",&bb);
       ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&aa);
   ^
./Main.c:7:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s",&bb);
 ^