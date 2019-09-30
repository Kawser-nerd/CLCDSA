#include<stdio.h>
int main(void){
  int a,b;
  char op;
  scanf("%d %c %d",&a,&op,&b);
  //printf("%c\n",op);
  if(op=='+') printf("%d\n",a+b);
  else printf("%d\n",a-b);
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:5:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%d %c %d",&a,&op,&b);
   ^