#include <stdio.h>
int main(void){
char s[50];
  int count=0;
  int n;
  scanf("%s",&s);
  for(n=0;n!=4;n++){
  if(s[n]=='+'){count++;}
   if(s[n]=='-'){count--;}
  }
  printf("%d",count);
  
return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:9: warning: format ‘%s’ expects argument of type ‘char *’, but argument 2 has type ‘char (*)[50]’ [-Wformat=]
   scanf("%s",&s);
         ^
./Main.c:6:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",&s);
   ^