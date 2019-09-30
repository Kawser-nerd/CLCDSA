#include<stdio.h>

int main(){
  int x,y;
  scanf("%c %c",&x, &y);
  if(x<y) printf("<");
  else if(x>y) printf(">");
  else printf("=");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:9: warning: format ‘%c’ expects argument of type ‘char *’, but argument 2 has type ‘int *’ [-Wformat=]
   scanf("%c %c",&x, &y);
         ^
./Main.c:5:9: warning: format ‘%c’ expects argument of type ‘char *’, but argument 3 has type ‘int *’ [-Wformat=]
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c %c",&x, &y);
   ^