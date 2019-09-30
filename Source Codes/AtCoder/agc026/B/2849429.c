#include<stdio.h>
#include<math.h>
long long gcm(long long a, long long b)
{
    long long r = a%b;
    while (r > 0)
    {
        a = b;
        b = r;
        r = a%b;
    }
    return b;
}
int main()
{
    int t;
    scanf("%d", &t);
    int i;
    long long a, b, c, d;
    for (i = 0; i < t; i++)
    {
        scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
        if (a < b)
            printf("No\n");
        else if (b > d)
            printf("No\n");
        else
        {
            if (a >= b && a >= c)
            {
                a = (a-c)%b;
                if (a == b)
                    a -= b;
                a += c;
            }
            if (a - b < 0 && a>c)
                printf("No\n");
            else if (c < b - gcm(b, d))
                printf("No\n");
            else
                printf("Yes\n");
        }
    }
    return 0;
} ./Main.c: In function ‘main’:
./Main.c:17:5: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
     scanf("%d", &t);
     ^
./Main.c:22:9: warning: ignoring return value of ‘scanf’, declared with attribute warn_unused_result [-Wunused-result]
         scanf("%lld %lld %lld %lld", &a, &b, &c, &d);
         ^