
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <limits.h>

#define MIN(a,b) ((a)<(b)?(a):(b))
#define MAX(a,b) ((a)>(b)?(a):(b))

#define MAXN 1000
#define MOD 1000000007

int64_t a[MAXN];
int64_t n, m, x, y, z;

uint64_t cache[MAXN];

static uint64_t take(int64_t cur)
{
    if (cache[cur] != 0)
        return cache[cur];
    uint64_t r = 1;
    for (int64_t i = cur+1; i < n; i++)
        if (a[i] > a[cur])
            r = (r + take(i))%MOD;
    cache[cur] = r;
    return r;
}

int main(int argc, char **argv)
{
    int ncases;
    scanf("%d", &ncases);
    for (int ccase = 0; ccase < ncases; ccase++)
    {
        scanf("%ld %ld %ld %ld %ld", &n, &m, &x, &y, &z);
        for (int64_t i = 0; i < m; i++)
            scanf("%ld", &a[i]);
        for (int64_t i = m; i < n; i++)
            a[i] = (x*a[i-m] + y*(i-m+1))%z;

        memset(cache, 0, sizeof(*cache)*n);

        uint64_t r = 0;
        for (int64_t i = 0; i < n; i++)
            r = (r + take(i))%MOD;
        r %= MOD;
        printf("Case #%d: %lu\n", ccase+1, r);
    }
}

