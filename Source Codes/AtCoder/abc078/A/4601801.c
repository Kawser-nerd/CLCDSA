#include <stdio.h>
#include <string.h>
int main(void){
char a[5],b[5];
  int k;
  scanf("%s %s",&a,&b);
  k=strcmp(a,b);
  if(k<0){printf("<");}
  if(k==0){printf("=");}
  if(k>0){printf(">");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[5]’ [-Wformat=]
   scanf("%s %s",&a,&b);
         ^
./Main.c:6:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[5]’ [-Wformat=]
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",&a,&b);
   ^