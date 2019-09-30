#include <stdio.h>
#define bignum 114514
#define th 3
void initArray(int s[], int len);
void init753(int s[]);
void make753(int s[], int start, int end, int disit);
int have(int a, int b[], int len);
int getdisit(int a);
int power(int a, int b);
int sft[bignum];
int check[th];
int main(void)
{
    initArray(sft, bignum);
    init753(sft);
    make753(sft, 0, 3, 0);
    initArray(check, th);
    init753(check);

    int n;
    scanf("%d", &n);
    int i = 0;
    int count = 0;
    while (sft[i] <= n)
    {
        if(have(sft[i], check, th))
        {
            count++;
        }
        i++;
    }
    printf("%d\n", count);

    // debug
    // printf("%d\n",sft[n]);
    // puts(have(sft[n], check,th)?"YES":"NO");
    return 0;
}

void initArray(int s[], int len)
{
    for (int i = 0; i < len; i++)
    {
        s[i] = 0;
    }
}

void init753(int s[])
{
    s[0] = 3;
    s[1] = 5;
    s[2] = 7;
}

void make753(int s[], int start, int end, int disit)
{
    //s[0] = 3, s[1] = 5, s[2] = 7???????
    if (disit == 9)
    {
        return;
    }

    int limit = end;
    while (start < limit)
    {
        s[end] = s[start] * 10 + 3;
        s[end + 1] = s[start] * 10 + 5;
        s[end + 2] = s[start] * 10 + 7;
        end += 3;
        start++;
    }
    make753(s, start, end, disit + 1);
}

int have(int a, int b[], int len)
{
    int disit = getdisit(a);
    int num[10];
    initArray(num, 10);
    while (disit > 0)
    {
        int c = a / power(10, disit - 1);
        c %= 10;
        num[c]++;
        disit--;
    }

    int d = 1;
    for (int i = 0; i < len; i++)
    {
        d *= num[b[i]];
    }

    if (d > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int getdisit(int a)
{
    if (a == 0)
    {
        return 1;
    }

    int disit = 0;
    while (a > 0)
    {
        a /= 10;
        disit++;
    }
    return disit;
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
./Main.c:21:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &n);
     ^