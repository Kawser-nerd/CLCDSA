#include<stdio.h>

int main(void)
{
    int a, b, c, d;

    scanf("%d%d", &a, &b);

    c = a + b;
    d = b - a;

    if (b % a == 0){
        printf("%d", c);
    }

    else
        printf("%d", d);

    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^