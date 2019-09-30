#include <stdio.h>
#define max 114515
int countNotZero(int a[], int length);
int power(int a, int b);
int main(void)
{
    int a;
    scanf("%d", &a);
    int s[max];
    for (int i = 0; i < max; i++)
    {
        s[i] = 0;
    }
    int disit = 0;
    while (a)
    {
        s[disit] = a % 2;
        a /= 2;
        disit++;
    }

    printf("%d\n",countNotZero(s,disit));

    while (disit > 0)
    {
        if (s[disit - 1])
        {
            printf("%d\n", s[disit - 1] * power(2, disit - 1));
        }
        disit--;
    }
    return 0;
}

int countNotZero(int a[], int length)
{
    int count = 0;
    for(int i = 0; i < length; i++)
    {
        if(a[i])
        {
            count++;
        }
    }
    return count;
}
int power(int a, int b)
{
    int c = 1;
    for (int i = 0; i < b; i++)
    {
        c *= a;
    }
    return c;
} ./Main.c: In function ‘main’:
./Main.c:8:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &a);
     ^