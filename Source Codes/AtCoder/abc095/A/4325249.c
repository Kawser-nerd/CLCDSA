#include <stdio.h>
int main(void){
char b[4];
  int a=0;
  scanf("%s",&b);
  if(b[0]=='o'){a++;}
    if(b[1]=='o'){a++;}
    if(b[2]=='o'){a++;}
  printf("%d",700+a*100);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[4]’ [-Wformat=]
   scanf("%s",&b);
         ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&b);
   ^