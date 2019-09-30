#include <stdio.h>
#include <string.h>
int main(void){
char a[10],b[10];
  scanf("%s %s",&a,&b);
  if((strcmp(a,"H")==0)&&(strcmp(b,"H")==0)){printf("H");}
  if((strcmp(a,"H")==0)&&(strcmp(b,"D")==0)){printf("D");}
  if((strcmp(a,"D")==0)&&(strcmp(b,"H")==0)){printf("D");}
  if((strcmp(a,"D")==0)&&(strcmp(b,"D")==0)){printf("H");}
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[10]’ [-Wformat=]
   scanf("%s %s",&a,&b);
         ^
./Main.c:5:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 3 has type ‘char (*)[10]’ [-Wformat=]
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s %s",&a,&b);
   ^