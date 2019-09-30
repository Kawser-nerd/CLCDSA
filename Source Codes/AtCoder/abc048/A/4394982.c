#include <stdio.h>
#include <string.h>
int main(void){
  char a[100],b[100],c[100];
scanf("%s %s %s",&a,&b,&c);
  printf("%.1s%.1s%.1s",a,b,c);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:7: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
 scanf("%s %s %s",&a,&b,&c);
       ^
./Main.c:5:7: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[100]’ [-Wformat=]
./Main.c:5:7: warning: format ‘%s’ expects argument of type ‘char *’, but argument 4 has type ‘char (*)[100]’ [-Wformat=]
./Main.c:5:1: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
 scanf("%s %s %s",&a,&b,&c);
 ^