#include<stdio.h>

int main(void)
{

   char a[3],b[3],c[3];

   scanf("%s",a);
   scanf("%s",b);
   scanf("%s",c);

   printf("%c%c%c\n",a[0],b[1],c[2]);
   
   return 0;
} ./Main.c: In function ‘main’:
./Main.c:8:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",a);
    ^
./Main.c:9:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",b);
    ^
./Main.c:10:4: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
    scanf("%s",c);
    ^