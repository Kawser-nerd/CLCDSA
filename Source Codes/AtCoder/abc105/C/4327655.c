#include <stdio.h>
#include <stdlib.h>
#define max 100
int main(void)
{
    int a;
    scanf("%d", &a);
    int s[max];
    for (int i = 0; i < max; i++)
    {
        s[i] = 0;
    }
    if (a == 0)
    {
        printf("%d\n", a);
        return 0;
    }

    int disit = 0;
    while (a != 1)
    {
        s[disit] = abs(a % (-2));
        a = (s[disit] - a) / 2;
        disit++;
    }
    s[disit] = a;

    while (disit >= 0)
    {
        printf("%d", s[disit]);
        disit--;
    }
    puts("");
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^