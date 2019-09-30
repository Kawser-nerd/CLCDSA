#include <stdio.h>
#define AMOUNT 3

int main(void)
{
    char a[4][4];
    scanf("%s%s%s",a[0],a[1],a[2]);
    printf("%c%c%c\n",a[0][0],a[1][1],a[2][2]);
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%s%s%s",a[0],a[1],a[2]);
     ^