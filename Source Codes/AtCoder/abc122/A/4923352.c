#include<stdio.h>

int main(void)
{
   char x;

   scanf("%c",&x);
   if(x=='A'){
        printf("T\n");
   }
   else if(x=='T'){
        printf("A");
   }
   else if(x=='C'){
        printf("G");
   }
   else if(x=='G'){
        printf("C");
   }
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%c",&x);
    ^