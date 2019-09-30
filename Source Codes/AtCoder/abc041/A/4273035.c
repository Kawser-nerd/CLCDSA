#include <stdio.h>
int main(){
char s[100];
int i;
scanf("%s",&s);
scanf("%d",&i);
printf("%c\n",s[i-1]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:7: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
 scanf("%s",&s);
       ^
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s",&s);
 ^
./Main.c:6:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%d",&i);
 ^