#include<stdio.h>

int main(void)
{
        char a[11],b[11],c[11];

        scanf("%s%s%s",a,b,c);

        printf("%c%c%c\n",a[0]-0x20,b[0]-0x20,c[0]-0x20);

        return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%s%s%s",a,b,c);
         ^