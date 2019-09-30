#include <limits.h>
#include <stdio.h>

int main()
{
    int cases, c, n, min, xor, i, x;
    unsigned long long sum;
    
    scanf("%d", &cases);
    for (c=1; c<=cases; c++)
    {
        scanf("%d", &n);
        sum = xor = 0;
        min = INT_MAX;
        for (i=0; i<n; i++)
        {
            scanf("%d", &x);
            if (x < min)
                min = x;
            xor ^= x;
            sum += x;
        }
        
        if (xor == 0)
            printf("Case #%d: %lld\n", c, sum-min);
        else
            printf("Case #%d: NO\n", c);
    }
    return 0;
}
