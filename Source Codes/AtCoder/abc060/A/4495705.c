#include <stdio.h>
#include <string.h>

int main(void){
char a[100],b[100],c[100];
  int o,p,q;
 scanf("%s",&a);
   scanf("%s",&b);
   scanf("%s",&c);
  o=strlen(a);
  p=strlen(b);
  q=strlen(c);
  if(a[o-1]==b[0]&&b[p-1]==c[0]){printf("YES");}
  else{printf("NO");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:8: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
  scanf("%s",&a);
        ^
./Main.c:8:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
    scanf("%s",&b);
          ^
./Main.c:9:10: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
    scanf("%s",&c);
          ^
./Main.c:7:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%s",&a);
  ^
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",&b);
    ^
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",&c);
    ^