#include <stdio.h>
int main(void){
  char s[1];
  scanf("%s",s);
  if(strcmp(s,"A")==0) printf("%d\n",1);
  if(strcmp(s,"B")==0) printf("%d\n",2);
  if(strcmp(s,"C")==0) printf("%d\n",3);
  if(strcmp(s,"D")==0) printf("%d\n",4);
  if(strcmp(s,"E")==0) printf("%d\n",5);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:6: warning: implicit declaration of function ‘strcmp’ [-Wimplicit-function-declaration]
   if(strcmp(s,"A")==0) printf("%d\n",1);
      ^
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%s",s);
   ^