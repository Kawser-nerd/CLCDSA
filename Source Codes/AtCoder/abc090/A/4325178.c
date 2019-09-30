#include <stdio.h>
int main(void){
char a[4];
  char b[4];
  char c[4];
  scanf("%s",&a);
    scanf("%s",&b);
    scanf("%s",&c);
  printf("%c%c%c\n",a[0],b[1],c[2]);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[4]’ [-Wformat=]
   scanf("%s",&a);
         ^
./Main.c:8:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[4]’ [-Wformat=]
     scanf("%s",&b);
           ^
./Main.c:9:11: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[4]’ [-Wformat=]
     scanf("%s",&c);
           ^
./Main.c:7:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&a);
   ^
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&b);
     ^
./Main.c:9:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s",&c);
     ^