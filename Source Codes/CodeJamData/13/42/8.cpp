#include <iostream>
#include <stdio.h>
#include <queue>

using namespace std;

int tc, n;

long long p;

void input()
{
    scanf("%d %lld", &n, &p);
}

long long worst(long long x)
{
    int i;
    long long s = x, t = (1ll << n) - (1 + x), r = 0;
    for(i = 1; i <= n; i++)
    {
        if(s == 0)
        {
            t >>= 1;
        }
        else
        {
            s--;
            s = s >> 1;
            t = (1ll << (n - i)) - (1 + s);
            r |= (1ll << (n - i));
        }
    }
    return r;
}

long long best(long long x)
{
    int i;
    long long s = x, t = (1ll << n) - (1 + x), r = 0;
    for(i = 1; i <= n; i++)
    {
        if(t == 0)
        {
            s >>= 1;
            r |= (1ll << (n - i));
        }
        else
        {
            t--;
            t = t >> 1;
            s = (1ll << (n - i)) - (1 + t);
        }
    }
    return r;
}

long long binary(long long s, long long t, long long (*check)(long long))
{
    long long m = ((s + t) >> 1) + 1;
    
    if(s == t)
    {
        return s;
    }
    
    if(check(m) < p)
    {
        return binary(m, t, check);
    }
    else
    {
        return binary(s, m - 1, check);
    }
}

void output()
{
    printf("Case #%d: %lld %lld\n", tc, binary(0, (1ll << n) - 1, worst), binary(0, (1ll << n) - 1, best));
}

int main()
{
    int t;
    
    freopen("/Users/protos37/Downloads/B-large.in", "r", stdin);
    freopen("/Users/protos37/Downloads/output.txt", "w", stdout);
    
    scanf("%d", &t);
    for(tc = 1; tc <= t; tc++)
    {
        input();
        output();
    }
    return 0;
}