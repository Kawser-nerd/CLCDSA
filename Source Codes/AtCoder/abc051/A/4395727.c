#include <stdio.h>
int main(void){
char a[100];
  int count;
  scanf("%s",&a);
  for(count=0;a[count]!='\0';count++){
  if(a[count]==','){a[count]=' ';}
  }
  printf("%s",a);
return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[100]’ [-Wformat=]
   scanf("%s",&a);
         ^
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&a);
   ^