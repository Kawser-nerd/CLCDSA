#include<stdio.h>

int main(void)
{
 char c;
 scanf("%c",&c);
 if     (c=='A') printf("T\n");
 else if(c=='T') printf("A\n");
 else if(c=='C') printf("G\n");
 else if(c=='G') printf("C\n");
 return 0;
} ./Main.c: In function ‘main’:
./Main.c:6:2: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
  scanf("%c",&c);
  ^