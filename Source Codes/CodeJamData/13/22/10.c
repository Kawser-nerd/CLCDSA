#include <math.h>
#include <stdio.h>

double prob(int n, int s)
{
    int i = 0, b = 1, r = 1;
    
    while (++i <= n - s)
    {
        b = b * (n - i + 1) / i;
        r += b;
    }
    
    return r * pow(0.5, n);
}

double solve(int n, int x, int y)
{
    int p;
    
    if (x == 0)
    {
        if (n >= (y+1) * (y+2) / 2)
            return 1.0;
        else
            return 0.0;
    }
    
    p = y + abs(x);
    
    n -= (p-1) * p / 2;
    // Need y+1 of n to fall the correct way, at most p can fall each way.
    if (n < y+1)
        return 0.0;
    if (n >= y+1 + p)
        return 1.0;
    
    return prob(n, y+1);
}

int main()
{
    int t, c;
    int n, x, y;
    
    scanf("%d", &t);
    for (c = 1; c <= t; c++)
    {
        scanf("%d%d%d", &n, &x, &y);
        printf("Case #%d: %f\n", c, solve(n, x, y));
    }
    
    return 0;
}
