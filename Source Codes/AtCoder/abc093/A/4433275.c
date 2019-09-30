#include <stdio.h>
int main(void){
char a[4];
  scanf("%s",&a);
  if((a[0]!=a[1])&&(a[0]!=a[2])&&(a[1]!=a[2])){printf("Yes\n");}
  else{printf("No\n");}
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[4]’ [-Wformat=]
   scanf("%s",&a);
         ^
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&a);
   ^