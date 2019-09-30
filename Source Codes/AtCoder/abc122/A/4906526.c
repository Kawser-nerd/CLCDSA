#include<stdio.h>
int main(){
  char b;
  scanf("%c",&b);
  if(b=='A') printf("T");
  else if(b=='T') printf("A");
  else if(b=='C') printf("G");
  else printf("C");
  return 0;
} ./Main.c: In function ‘main’:
./Main.c:4:3: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
   scanf("%c",&b);
   ^