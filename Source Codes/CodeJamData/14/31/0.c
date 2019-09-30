#include <stdio.h>

/* Google Code Jam Round 1C 2014
 * Problem A. Part Elf
 * Solution in C
 * By Smithers
 */

long long gcd(long long a, long long b)
{
    long long c;
    while (a)
    {
        c = b % a;
        b = a;
        a = c;
    }
    return b;
}

int main()
{
    int t, ti;
    long long p, q;
    long long g;
    int y;
    
    scanf("%d", &t);
    for (ti = 1; ti <= t; ti++)
    {
        scanf("%lld/%lld", &p, &q);
        g = gcd(p, q);
        p /= g;
        q /= g;
        if (q & q-1)
        {
            printf("Case #%d: impossible\n", ti);
        }
        else
        {
            y = 0;
            while (q > p)
            {
                y++;
                q /= 2;
            }
            printf("Case #%d: %d\n", ti, y);
        }
    }
    return 0;
}
