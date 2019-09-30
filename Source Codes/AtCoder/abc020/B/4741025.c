#include <stdio.h>
int retdigit(int a);
int power(int a, int b);
int main(void)
{
    int a, b;
    scanf("%d%d", &a, &b);
    int b_digit = retdigit(b);
    int tmp = power(10, b_digit);
    int ans = a * tmp + b;
    printf("%d\n", ans * 2);
    return 0;
}

int retdigit(int a)
{
    int digit = 0;
    while (a > 0)
    {
        a /= 10;
        digit++;
    }
    return digit;
}

int power(int a, int b)
{
    int val = 1;
    for (int i = 0; i < b; i++)
    {
        val *= a;
    }
    return val;
} ./Main.c: In function ‘main’:
./Main.c:7:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d%d", &a, &b);
     ^